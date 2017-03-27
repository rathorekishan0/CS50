/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<strings.h>
#include<malloc.h>


#include "dictionary.h"
typedef struct node
{
    char word[LENGTH+1];
    struct node *next;
}
node;
node *hashtable[26];
int n=0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    /*int i=0;
    while(word[i]!='\0')
    {
        word[i]=toupper(word[i]);
        i++;
    }
    word[i]='\0';
    */
    node *cursor;
    int index=(toupper(word[0]))%65;
    if(hashtable[index]!=NULL)
    {
        cursor=hashtable[index]->next;
        while(cursor!=NULL)
        {
            if(strcasecmp(cursor->word,word)==0)
            return true;
            else
            cursor=cursor->next;
        }
    }    
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int i;
    for( i=0;i<26;i++)
    {
        hashtable[i]=NULL;
    }   
    char word[LENGTH+1];
    int index;
    FILE *fp = fopen(dictionary, "r");
    while(fscanf(fp,"%s",word)!=EOF)
    {
        //printf("%s",word);
        node *new_node=malloc(sizeof(node));
        if(new_node==NULL)
        {
            unload();
            return false;
        }
        strcpy(new_node->word,word);
        index=(toupper(word[0]))%65;
        if(hashtable[index]==NULL)
        {
            hashtable[index]=malloc(sizeof(node));
            hashtable[index]->next=new_node;
            new_node->next=NULL;
        }
        else
        {
            new_node->next=hashtable[index]->next;
            hashtable[index]->next=new_node;
        }
    }
    n=1;
    // TODO
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    int s=0;
    if(n==1)
    {
        node *cursor;
        for(int i=0;i<26;i++)
        {
            if(hashtable[i]!=NULL)
            {
                cursor=hashtable[i]->next;
                while(cursor!=NULL)
                {
                    s++;
                    cursor=cursor->next;
                }
            }    
        }
        return s;
    }
    else
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    node* cursor;
    for(int i=0;i<=26;i++)
    {
        if(hashtable[i]!=NULL)
        {
            cursor=hashtable[i]->next;
            while(cursor!=NULL)
            {
                node* temp=cursor;
                cursor=cursor->next;
                free(temp);
            }
        }
    }
    // TODO
return true;
}
