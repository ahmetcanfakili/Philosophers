/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:24:41 by afakili           #+#    #+#             */
/*   Updated: 2022/08/18 16:24:41 by afakili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

/*
Başarılı durumda 0 döner.
start_routine thread tarafından çalıştırılacak olan fonksiyonu gösterir.
arg ise thread tarafından çalıştırılacak fonksiyona geçirilecek void*'a cast edilmiş 
genel bir veri yapısını göstermektedir.
*/

void *worker(void *data)
{
    char *name = (char*)data;
    for (int i=0; i<120; i++) 
    {
        usleep(5000);
        printf("Hello from thread %s\n", name);
    }
    printf("Thread %s done...\n", name);
    return NULL;
}

int main() 
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, worker, "Ali");
    pthread_create(&th2, NULL, worker, "Batman");
    sleep(5);
    printf("Exiting from main program\n");
    return 0;
}

