#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word
{
    char *data;
};

struct sentence
{
    struct word *data;
    int word_count; //denotes number of words in a sentence
};

struct paragraph
{
    struct sentence *data;
    int sentence_count; //denotes number of sentences in a paragraph
};

struct document
{
    struct paragraph *data;
    int paragraph_count; //denotes number of paragraphs in a document
};
struct document get_document(char *text)
{
    int i = 0, j = 0, m = 0, n = 0, no_of_para = 1, no_of_sentence = 0;
    int no_of_words = 1, no_of_char = 0, idx = 0;
    int par[100];
    int sen[100];
    int wor[100];
    int chr[100];
    int par_idx = 0, sen_idx = 0, wor_idx = 0, chr_idx = 0;
    struct document return_doc;
    par[par_idx++] = -1;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '\n')
        {
            par[par_idx++] = i;
            no_of_para++;
        }
    }
    par[par_idx++] = strlen(text);
    struct paragraph *return_para;
    return_para = (struct paragraph *)calloc(no_of_para, sizeof(struct paragraph));
    return_doc.data = return_para;
    return_doc.paragraph_count = no_of_para;
    for (i = 1; i < par_idx; i++)
    {
        no_of_sentence = 0;
        sen_idx = 0;
        sen[sen_idx++] = par[i - 1] + 1;
        for (j = par[i - 1] + 1; j < par[i]; j++)
        {
            if (text[j] == '.')
            {
                no_of_sentence++;
                if (sen_idx == 0)
                {
                    sen[sen_idx++] = j;
                }
                else
                {
                    sen[sen_idx++] = j + 1;
                }
            }
        }
        struct sentence *return_sen;
        return_sen = (struct sentence *)calloc(no_of_sentence, sizeof(struct sentence));
        return_para[i - 1].sentence_count = no_of_sentence;
        return_para[i - 1].data = return_sen;
        for (j = 1; j < sen_idx; j++)
        {
            no_of_words = 1;
            wor_idx = 0;
            wor[wor_idx++] = sen[j - 1];
            for (m = sen[j - 1]; m < sen[j]; m++)
            {
                if (text[m] == ' ')
                {
                    no_of_words++;
                    wor[wor_idx++] = m + 1;
                }
            }
            wor[wor_idx++] = sen[j] - 1;
            struct word *return_word;
            return_word = (struct word *)calloc(no_of_words, sizeof(struct word));
            return_sen[j - 1].word_count = no_of_words;
            return_sen[j - 1].data = return_word;
            for (m = 1; m < wor_idx; m++)
            {
                no_of_char = 0;
                chr_idx = 0;
                for (n = wor[m - 1]; n < wor[m]; n++)
                {
                    no_of_char++;
                    chr[chr_idx++] = text[n];
                }
                char *ch;
                if (m == wor_idx - 1)
                {
                    ch = (char *)calloc(no_of_char, sizeof(char));
                    return_word[m - 1].data = ch;
                }
                else
                {
                    ch = (char *)calloc(no_of_char - 1, sizeof(char));
                    return_word[m - 1].data = ch;
                }
                idx = 0;
                for (n = 0; n < chr_idx; n++)
                {
                    if (chr[n] != ' ')
                    {
                        ch[idx++] = chr[n];
                    }
                }
            }
        }
    }
    return return_doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n)
{
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m)
{
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k)
{
    return Doc.data[k - 1];
}

void print_word(struct word w)
{
    printf("%s", w.data);
}

void print_sentence(struct sentence sen)
{
    for (int i = 0; i < sen.word_count; i++)
    {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1)
        {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para)
{
    for (int i = 0; i < para.sentence_count; i++)
    {
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc)
{
    for (int i = 0; i < doc.paragraph_count; i++)
    {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char *get_input_text()
{
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++)
    {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main()
{
    char *text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int type;
        scanf("%d", &type);

        if (type == 3)
        {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2)
        {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else
        {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }
}