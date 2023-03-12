#pragma once
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct _PRA
{
    int total_frames;
    int total_pages;
    int total_page_faults;
    int frame_update;

    int *list_pages;
    int *page_table;
    char *page_faults;

    
    bool (*IsPageExisted)(struct _PRA *, int);

    bool (*IsFramesFull)(struct _PRA *, int);

    void (*CopyLastFrames)(struct _PRA *, int);

    void (*UpdatePageFrame)(struct _PRA *, int);

    void (*StartPaging)(struct _PRA *);

    void (*DisplayPages)(struct _PRA *);

    void (*DisplayPageTable)(struct _PRA *);

    void (*DisplayPageFaults)(struct _PRA *);
} PRA;
void StartPaging(PRA *const self) {}
void DisplayPages(PRA *const self)
{
	int i;
    printf("\n");
    for (i = 0; i < self->total_pages; ++i)
        printf(" %d |", self->list_pages[i]);
	printf("\n");
}

void DisplayPageTable(PRA *const self)
{
	int i,j;
	
    for ( i = 0; i < self->total_frames; ++i)
    {
    	printf("\n");
        for (j = 0; j < self->total_pages; ++j)
        {
            int value = self->page_table[i * self->total_pages + j];
            if (value == -1) printf("   |");
            else printf(" %d |", value);
        }
    }
}

void DisplayPageFaults(PRA *const self)
{
  printf("\n\nNumber of Page Faults: %d\n", self->total_page_faults);
}


void UpdatePageFrame(PRA *const self, int page_index)
{
    int mem_index = self->total_pages * self->frame_update + page_index;
    self->page_table[mem_index] = self->list_pages[page_index];
    self->page_faults[page_index] = '*';
    self->total_page_faults++;

    self->frame_update++;
    if (self->frame_update >= self->total_frames)
        self->frame_update = 0;
}

void CopyLastFrames(PRA *const self, int page_index)
{
	int i;
    for (i = 0; i < self->total_frames; ++i)
    {
        int last_mem_index = self->total_pages * i + page_index - 1;
        int last_mem_value = self->page_table[last_mem_index];
        self->page_table[self->total_pages * i + page_index] = last_mem_value;
    }
}
bool IsFramesFull(PRA *const self, int page_index)
{
	int i;
    for ( i = 0; i < self->total_frames; ++i)
    {
        int mem_index = self->total_pages * i + page_index;
        if (self->page_table[mem_index] == -1)
            return false;
    }
    return true;
}
bool IsPageExisted(PRA *const self, int page_index)
{
	int  i;
    int page_value = self->list_pages[page_index];
    for (i = 0; i < self->total_frames; ++i)
    {
        int last_mem_index = self->total_pages * i + page_index - 1;
        if (self->page_table[last_mem_index] == page_value)
            return true;
    }
    return false;
}
PRA *new_PRA(int total_frames, char str_processes[20])
{
	int i,j;
    PRA *pra = NULL;
    pra = (PRA *)malloc(sizeof(PRA));
    if (pra == NULL)
        return NULL;

    pra->total_frames = total_frames;
    pra->total_pages = strlen(str_processes);
    pra->total_page_faults = 0;
    pra->frame_update = 0;

    pra->list_pages = (int *)malloc(pra->total_pages * sizeof(int));
    if (pra->list_pages == NULL)
        return NULL;

    pra->page_table = (int *)malloc(pra->total_frames * pra->total_pages * sizeof(int));
    if (pra->page_table == NULL)
        return NULL;

    pra->page_faults = (char *)malloc(pra->total_pages * sizeof(char));
    if (pra->page_faults == NULL)
        return NULL;

    for ( i = 0; i < pra->total_pages; ++i)
    {
        *(pra->list_pages + i) = str_processes[i] - '0';
        *(pra->page_faults + i) = ' ';
    }

    for (i = 0; i < pra->total_frames; ++i)
        for ( j = 0; j < pra->total_pages; ++j)
            pra->page_table[i * pra->total_pages + j] = -1;

    pra->IsPageExisted = &IsPageExisted;
    pra->IsFramesFull = &IsFramesFull;
    pra->CopyLastFrames = &CopyLastFrames;
    pra->UpdatePageFrame = &UpdatePageFrame;

    pra->StartPaging = &StartPaging;
    pra->DisplayPages = &DisplayPages;
    pra->DisplayPageTable = &DisplayPageTable;
    pra->DisplayPageFaults = &DisplayPageFaults;

    return pra;
}


void StartFIFO(PRA *const self)
{
	int i;
    for (i = 0; i < self->total_pages; ++i)
    {
        self->CopyLastFrames(self, i);
        if (!self->IsPageExisted(self, i))
            self->UpdatePageFrame(self, i);
    }
}

PRA *new_FIFO(int num_frames, char str_pages[20])
{
    PRA *pra = new_PRA(num_frames, str_pages);
    pra->StartPaging = &StartFIFO;
    return pra;
}
void delete_PRA(PRA *self)
{
    free(self->list_pages);
    free(self->page_table);
    free(self->page_faults);
    self = NULL;
}
int main()
{
	int choice, num_frames;
	char str_pages[20];
	PRA *pra;
	printf("Enter the input string : ");
	scanf("%s", str_pages);
	printf("Enter the no of  frames: ");
	scanf("%d", &num_frames);
	pra = new_FIFO(num_frames, str_pages);
	pra->StartPaging(pra);
	pra->DisplayPages(pra);
	pra->DisplayPageTable(pra);
	pra->DisplayPageFaults(pra);

	delete_PRA(pra);
	return 0;
	
}





