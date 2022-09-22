/*PAT-1 - C Program to Display Student Mark Sheets Using Structure
Write a C Program to Display Student Mark Sheets Using Structure. First, 
read the total number of students ‘n’ in a class. 
After that, read the student’s information 
(like the name of the student, register number of the student, mark of subject-1,
 mark of subject-2, mark of subject-3, 
 mark of subject-4 and mark of subject-5) 
 for the given ‘n’ number of students. 
 For each and every student calculates Total and Average. 
 If the average is greater than or equal to 75 then marked his class as “Distinction”. 
 If the average is greater than or equal to 60 then marked his class as “First Class”. 
 If the average is greater than or equal to 50 then marked his class as “Second Class”. 
 If the average is greater than or equal to 40 then marked his class as “Third Class”. 
 If the student scored less than 40 in any one subject, 
 then mark his Status as “Fail” otherwise “Pass”. There is no class for failure students. 
 In last print the mark statement for each and every student with their name, 
 register number, mark of subject-1, mark of subject-2, mark of subject-3, 
 mark of subject-4, and mark of subject-5, Total, Average, Class and Status.*/

#include<stdio.h>
int main()
{
    struct students
    {
        char name[50];
        int reg_no;
        int mark_1;
        int mark_2;
        int mark_3;
        int mark_4;
        int mark_5;
    };
    int n,i,total;
    float average;
    struct students stu;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",&stu.name);
        scanf("%d",&stu.reg_no);
        scanf("%d",&stu.mark_1);
        scanf("%d",&stu.mark_2);
        scanf("%d",&stu.mark_3);
        scanf("%d",&stu.mark_4);
        scanf("%d",&stu.mark_5);
        total=stu.mark_1+stu.mark_2+stu.mark_3+stu.mark_4+stu.mark_5;
        average=(stu.mark_1+stu.mark_2+stu.mark_3+stu.mark_4+stu.mark_5)/5;
        printf("Mark Sheet\n");
        printf("Name of Student:%s\n",stu.name);
        printf("Roll No:%d\n",stu.reg_no);

        printf("Subject 1:%d\n",stu.mark_1);
        printf("Subject 1:%d\n",stu.mark_2);
        printf("Subject 1:%d\n",stu.mark_3);
        printf("Subject 1:%d\n",stu.mark_4);
        printf("Subject 1:%d\n",stu.mark_5);
        printf("Total Marks:%d\n",total);
        printf("Average Marks:%f\n",average);
        
        if(average>=75)
        {
            printf("Class:Distinction\n");
        }
        else if(average>=60)
        {
            printf("Class:First Class\n");
        }
        else if(average>=50)
        {
            printf("Class:Second Class\n");
        }
        else if(average>=40)
        {
            printf("Class:Third Class\n");
        }
        else
        {
            continue;
        }
        
        if((stu.mark_1<40)||(stu.mark_2<40)||(stu.mark_3<40)||(stu.mark_4<40)||(stu.mark_5<40))
        {
            printf("Status:Fail\n");
        }
        else
        {
            printf("Status:Pass\n");
        }
    }
    return 0;
}

