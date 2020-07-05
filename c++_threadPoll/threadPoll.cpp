#include <iostream>
#include <thread>
#include <cstring>
#include <unistd.h>
using namespace std;

#define LL_ADD(item, list) do{  \
    item->prev = NULL;          \
    item->next = list;          \
    if(list != NULL) list->prev = item;          \
    list = item;                \
}while(0)

#define LL_REMOVE(item, list) do{                             \
    if(item->prev != NULL)item->prev->next = item->next;      \
    else{list = item->next; }                                  \
    if(item->next != NULL) item->next->prev = item->prev;      \
    item->prev = item->next = NULL;                                             \
}while(0)
/** 
 * 线程池由三部分组成：
 *         １执行队列
 *         ２任务队列
 *         ３管理组件
 * */
//执行队列
struct NWORKER{
    pthread_t thread;
    struct NMANAGER *pool;
    int terminate;

    NWORKER *prev;
    NWORKER *next;

};


//任务队列
struct NJOB{
    void (*func)(void *user_data);
    void *user_data;

    struct NJOB* prev;
    struct NJOB* next;
};

struct NMANAGER
{
    /* data */
    struct NWORKER *workers;
    struct NJOB *jobs;

    pthread_cond_t jobs_cond;
    pthread_mutex_t jobs_mutex;
};


typedef struct NMANAGER nThreadPool; 

static void *nThreadCallback(void *arg){
    struct NWORKER* worker = (struct NWORKER*)arg;
    while(1){
        pthread_mutex_lock(&worker->pool->jobs_mutex);
        while(worker->pool->jobs == NULL){
            if(worker->terminate) break;
            //打开锁－>进入休眠状态－>等待条件变量被发送信号或着广播－>唤醒－>锁定
            pthread_cond_wait(&worker->pool->jobs_cond, &worker->pool->jobs_mutex);
        }

        if(worker->terminate){
            pthread_mutex_unlock(&worker->pool->jobs_mutex);
            break;
        }

        struct NJOB *job = worker->pool->jobs;
        LL_REMOVE(job, worker->pool->jobs);
        pthread_mutex_unlock(&worker->pool->jobs_mutex);

        job->func(job->user_data);
    }
    free(worker);
    pthread_exit(NULL);     //退出当前线程
    //pthread_cancel(pthreadID);       //退出线程id标识的线程
}
//thread Poll create, API
int nThreadPoolCreate(nThreadPool *pool, int numWorkers){
    if(numWorkers < 1) numWorkers = 1;
    if(pool == NULL) return -1;
    memset(pool, 0, sizeof(nThreadPool));

    pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
    memcpy(&pool->jobs_cond, &blank_cond, sizeof(blank_cond));

    pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
    memcpy(&(pool->jobs_mutex), &blank_mutex, sizeof(blank_mutex));

    // NWORKER * worker = new NWORKER;
    // pthread_create(&(worker->thread), NULL, NULL, NULL);
    // LL_ADD(worker, pool->workers);

    for(int i = 0; i < numWorkers; i++){
        struct NWORKER * worker = (struct NWORKER *)malloc(sizeof(struct NWORKER));
        if(worker == nullptr){
            perror("malloc");
            return -2;
        }
        memset(worker, 0, sizeof(struct NWORKER));
        worker->pool = pool;
        int ret = pthread_create(&(worker->thread), NULL, nThreadCallback, worker);
        if(ret){
            perror("pthread_create");
            free(worker);
            return -3;
        }
        LL_ADD(worker, pool->workers);
    }
}

void nThreadPoolDestrooy(nThreadPool* pool){
    struct NWORKER *worker = NULL;
    for(worker = pool->workers; worker != NULL; worker = worker->next){
        worker->terminate = 1;
    }
    pthread_mutex_lock(&pool->jobs_mutex);
    pthread_cond_broadcast(&pool->jobs_cond);       //唤起所有线程
    pthread_mutex_unlock(&pool->jobs_mutex);    
}
void nThreadPoolPush(nThreadPool* pool, NJOB* job){
    pthread_mutex_lock(&pool->jobs_mutex);
    LL_ADD(job, pool->jobs);
    pthread_cond_signal(&pool->jobs_cond);
    pthread_mutex_unlock(&pool->jobs_mutex);
}



#if 1

// 0 - 1000计数
// 创建1000个线程，每个线程打印一个数字
void func(void *user_data){
    cout << *(int *)user_data << endl;
    
    delete (int *)user_data;
}
int main(){
    nThreadPool * pool = new nThreadPool;
    nThreadPoolCreate(pool, 1);
    sleep(2);
    for(int i = 0; i <= 1000; i++){
        NJOB* job = new NJOB;
        int *p = new int;
        *p = i;
        job->user_data = p;
        job->func = func;
        nThreadPoolPush(pool, job);
    }
    
}
#endif






// #include<pthread.h>
// #include<unistd.h>
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
 
// static pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
// static pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
 
// struct node {
//     int n_number;
//     struct node *n_next;
// } *head=NULL; /*[thread_func]*/
 
// /*释放节点内存*/
// static void cleanup_handler(void*arg) {
//     printf("Clean up handler of second thread.\n");
//     free(arg);
//     (void)pthread_mutex_unlock(&mtx);
// }
 
// static void *thread_func(void *arg) {
//     struct node*p=NULL;
//     pthread_cleanup_push(cleanup_handler,p);
 
//     pthread_mutex_lock(&mtx);
//     //这个mutex_lock主要是用来保护wait等待临界时期的情况，
//     //当在wait为放入队列时，这时，已经存在Head条件等待激活
//     //的条件，此时可能会漏掉这种处理
//     //这个while要特别说明一下，单个pthread_cond_wait功能很完善，
//     //为何这里要有一个while(head==NULL)呢？因为pthread_cond_wait
//     //里的线程可能会被意外唤醒，如果这个时候head==NULL，
//     //则不是我们想要的情况。这个时候，
//     //应该让线程继续进入pthread_cond_wait
//     while(1) {
//         while(head==NULL) {
//             pthread_cond_wait(&cond,&mtx);
//         }
//         //pthread_cond_wait会先解除之前的pthread_mutex_lock锁定的mtx，
//         //然后阻塞在等待队列里休眠，直到再次被唤醒
//         //（大多数情况下是等待的条件成立而被唤醒，唤醒后，
//         //该进程会先锁定先pthread_mutex_lock(&mtx);，
//         //再读取资源用这个流程是比较清楚的
//         /*block-->unlock-->wait()return-->lock*/
//         p=head;
//         head=head->n_next;
//         printf("Got%dfromfrontofqueue\n",p->n_number);
//         free(p);
//     }
//     pthread_mutex_unlock(&mtx);//临界区数据操作完毕，释放互斥锁
 
//     pthread_cleanup_pop(0);
//     return 0;
// }
 
// int main(void) {
//     pthread_t tid;
//     int i;
//     struct node *p;
//     pthread_create(&tid,NULL,thread_func,NULL);
//     //子线程会一直等待资源，类似生产者和消费者，
//     //但是这里的消费者可以是多个消费者，
//     //而不仅仅支持普通的单个消费者，这个模型虽然简单，
//     //但是很强大
//     for(i=0;i<10;i++) {
//         p=(struct node*)malloc(sizeof(struct node));
//         p->n_number=i;
//         pthread_mutex_lock(&mtx);//需要操作head这个临界资源，先加锁，
//         p->n_next=head;
//         head=p;
//         pthread_cond_signal(&cond);
//         pthread_mutex_unlock(&mtx);//解锁
//         sleep(1);
//     }
//     printf("thread1wannaendthecancelthread2.\n");
//     pthread_cancel(tid);
//     //关于pthread_cancel，有一点额外的说明，它是从外部终止子线程，
//     //子线程会在最近的取消点，退出线程，而在我们的代码里，最近的
//     //取消点肯定就是pthread_cond_wait()了。
//     pthread_join(tid,NULL);
//     printf("Alldone--exiting\n");
//     return 0;
// }