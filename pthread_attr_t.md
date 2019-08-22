#### 线程属性

```C
//线程属性结构体如下：
typedef struct{
   int                      detachstate;    //线程的分离状态
   int                      schedpolicy;    //线程调度策略
   struct sched_param       schedparam;     //线程的调度参数
   int                      inheritsched;   //线程的继承性
   int                      scope;          //线程的作用域
   size_t                   guardsize;      //线程栈末尾的警戒缓冲区大小
   int                      stackaddr_set;
   void                     *stackaddr;     //线程栈的位置
   size_t                   stacksize;      //线程栈的大小
}pthread_attr_t;
```

```C
//初始化和资源回收函数
#include <pthread.h>
int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
                       //Both return: 0 if OK, error number on failure
```
##### 一、分离属性
在默认情况下，线程的终止状态会保存直到对该线程调用`pthread_join`，如果线程已经被分离，线程的底层资源可以在线程终止时立即被回收。可以调用`pthread_detach`分离线程。
```C
#include <pthread.h>
int pthread_detach(pthread_t tid);
                        //Returns: 0 if OK, error number on failure
```
也可以创建时就处于分离状态。
We can use the `pthread_attr_setdetachstate` function to set the detachstate thread attribute to one of two legal values: `PTHREAD_CREATE_DETACHED` to start the thread in the detached state or `PTHREAD_CREATE_JOINABLE` to start the thread normally, so its termination status can be retrieved by the application.
```C
#include <pthread.h>
int pthread_attr_getdetachstate(const pthread_attr_t *restrict attr, int *detachstate);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
                            //Both return: 0 if OK, error number on failure
```

##### 二、线程调度策略

```C
int pthread_attr_getschedpolicy(pthread_attr_t  *attr, int *schedpolicy);
int pthread_attr_setschedpolicy(pthread_attr_t  *attr, int schedpolicy);
```
参数`schedpolicy`调度策略:
`SCHED_FIFO`   先进先出；
`SCHED_RR`     轮换；
`SCHED_OTHER`  其他

调度参数：
```C
int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *schedparam);
int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *schedparam);
```

```C
//usr/include /bits/sched.h
struct sched_param{
    int sched_priority;
};
```

系统支持的最大和最小的优先级值可以用函数
```C
int sched_get_priority_max( int policy );
int sched_get_priority_min( int policy );
```

三、线程堆栈

```C
int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize);
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
```

四、例子

```C
int pthreadGetPriorityScope(int *minPriority, int *maxPriority){
    /* get the allowable priority range for the scheduling policy */
    if (minPriority != NULL){
        (*minPriority) = sched_get_priority_min(SCHED_RR);
        if (*minPriority == -1)
            return -1;
    }
    if (maxPriority != NULL){
        (*maxPriority) = sched_get_priority_max(SCHED_RR);
        if (*maxPriority == -1)
            return -1;
    }
    printf("priority: min = %d, max = %d\n", *minPriority, *maxPriority);
    return 0;
}

static int setPthreadAttr(pthread_attr_t *attr, int priority, size_t* stacksize{
    int rval;
    struct sched_param	params;
    int maxPriority, minPriority;

    rval = pthread_attr_init(attr);
    if (rval != 0)
        return rval;

    /* use the round robin scheduling algorithm */
    //设置线程调度模式，循环
    rval = pthread_attr_setschedpolicy(attr, SCHED_RR);//轮转法
    if (rval != 0){
        pthread_attr_destroy(attr);
        return rval;
    }

    /* set the thread to be detached */
    //设置为分离线程，让线程结束的话释放自己的资源
    rval = pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);
    if (rval != 0){
        pthread_attr_destroy(attr);
        return rval;
    }

    /* first get the scheduling parameter, then set the new priority */
    //设置线程的优先级
    // pthread_attr_getschedparam  得到线程的调度参数
    // pthread_attr_setschedparam  设置线程的调度参数
    rval = pthread_attr_getschedparam(attr, &params);
    if (rval != 0){
        pthread_attr_destroy(attr);
        return rval;
    }

    rval = pthreadGetPriorityScope(&minPriority, &maxPriority);
    if (rval != 0){
        pthread_attr_destroy(attr);
        return rval;
    }
    if (priority < minPriority){
        priority = minPriority;
    }
    else if (priority > maxPriority){
        priority = maxPriority;
    }
    params.sched_priority = priority;
    rval = pthread_attr_setschedparam(attr, &params);
    if (rval != 0){
        pthread_attr_destroy(attr);
        return rval;
    }

    /* when set stack size, we define a minmum value to avoid fail */
    if (*stacksize < PTHREAD_STACK_MIN)
        *stacksize = PTHREAD_STACK_MIN;

    rval = pthread_attr_setstacksize(attr, *stacksize);
    if (rval != 0){
        pthread_attr_destroy(attr);
        return rval;
    }
    return 0;
}
```
_____________
参考资料：
《UNIX环境高级编程》
