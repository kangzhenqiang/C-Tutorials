#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _MY_SEQQUEUE_H
#define _MY_SEQQUEUE_H

typedef void SeqQueue;

SeqQueue* SeqQueue_Create(int capacity);

void SeqQueue_Destory(SeqQueue* queue);

void SeqQueue_Clear(SeqQueue* queue);

int SeqQueue_Append(SeqQueue* queue, void* item);

void* SeqQueue_Retrieve(SeqQueue* queue);

void* SeqQueue_Header(SeqQueue* queue);

int SeqQueue_Length(SeqQueue* queue);

int SeqQueue_Capacity(SeqQueue* queue);

#endif // !_MY_SEQQUEUE_H


