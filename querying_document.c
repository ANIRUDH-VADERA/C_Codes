#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
int NO_OF_PARA = 0;
int SEN[100];
int WORD[100][100];
int CHAR[100][100][100];

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m, int n)
{
    return document[n - 1][m - 1][k - 1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m)
{
    return document[m - 1][k - 1];
}

char ***kth_paragraph(char ****document, int k)
{
    return document[k - 1];
}

char ****get_document(char *text)
{
    int i = 0, j = 0, m = 0, n = 0, no_of_para = 1, no_of_sentence = 0, no_of_words = 1, no_of_char = 0, idx = 0;
    int par[100];
    int sen[100];
    int wor[100];
    int chr[100];
    int par_idx = 0, sen_idx = 0, wor_idx = 0, chr_idx = 0;
    par[par_idx++] = -1;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '\n')
        {
            par[par_idx++] = i;
            no_of_para++;
        }
    }
    NO_OF_PARA = no_of_para;
    par[par_idx++] = strlen(text);
    char ****return_doc = (char ****)calloc(no_of_para, sizeof(char ***));
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
        SEN[i - 1] = no_of_sentence;
        return_doc[i - 1] = (char ***)calloc(no_of_sentence, sizeof(char **));
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
            WORD[i - 1][j - 1] = no_of_words;
            return_doc[i - 1][j - 1] = (char **)calloc(no_of_words, sizeof(char *));
            for (m = 1; m < wor_idx; m++)
            {
                no_of_char = 0;
                chr_idx = 0;
                for (n = wor[m - 1]; n < wor[m]; n++)
                {
                    no_of_char++;
                    chr[chr_idx++] = text[n];
                }
                if (m == wor_idx - 1)
                {
                    CHAR[i - 1][j - 1][m - 1] = no_of_char;
                    return_doc[i - 1][j - 1][m - 1] = (char *)calloc((no_of_char), sizeof(char));
                }
                else
                {
                    CHAR[i - 1][j - 1][m - 1] = no_of_char - 1;
                    return_doc[i - 1][j - 1][m - 1] = (char *)calloc((no_of_char - 1), sizeof(char));
                }
                idx = 0;
                for (n = 0; n < chr_idx; n++)
                {
                    if (chr[n] != ' ')
                    {
                        return_doc[i - 1][j - 1][m - 1][idx++] = chr[n];
                    }
                }
            }
        }
    }
    return return_doc;
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

void print_word(char *word)
{
    printf("%s", word);
}

void print_sentence(char **sentence)
{
    int word_count;
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++)
    {
        printf("%s", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char ***paragraph)
{
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++)
    {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()
{
    char *text = get_input_text();
    char ****document = get_document(text);

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
            char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2)
        {
            int k, m;
            scanf("%d %d", &k, &m);
            char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else
        {
            int k;
            scanf("%d", &k);
            char ***paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }
}