#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<time.h>
//using namespace std;
char user1B[]="First1,Last1,Acct1,1234"; char user2B[]="First2,Last2,Acct2,abcd"; char user1L[]="First3,Last3,Acct3,fffff";
int bookID=5;	//FILE *initBook;initBook=popen("cat myLib.txt | wc -l","r"); bookId=stoi(fgets(char,sizeof(char)),initBook);
int userId;
char bookCheckOut[11] ="2018-11-29"; char bookCheckRet[11]="2018-12-29"; char bookCurrent[11]="2018-11-29"; 
int bookCheckOutConv=20181129;int bookCheckRetConv=20181229;int bookCurrentConv=20181129;
//void showMenuB();void showMenuL();void optionMenu();void sortBookT();void bookIn();void bookOut();void addBook();void sortBookT();void bookIn();void bookOut();void addBook();void delBook();void checkOutBook();void retBook();
void showMenuB(){
	printf("\tEnter “q” for book query by author sorted by book title\n");
	printf("\tEnter “s” for book status query by name\n");
	printf("\tEnter “u” to list books checked out by a given user\n");
	printf("\tEnter “x” to quit\n");
	return ;
}
void showMenuL(){
	printf("\tEnter “a” to add a book into library\n");
	printf("\tEnter “d” to delete a book from library\n");
	printf("\tEnter “o” to check out a book\n");
	printf("\tEnter “r” to return a book\n");
	printf("\tEnter “c”  to check current users info \n");
	printf("\tEnter “u” to add library users acct info\n");
	printf("\tEnter “n” to delete library users acct info\n");
	printf("\tEnter “x” to quit\n");
	return;
}
int compare_strings(char *first, char *second) {
   while (*first == *second) {
      if (*first == '\0' || *second == '\0')
         break;
      first++;
      second++;
   }

   if (*first == '\0' && *second == '\0')
      return 0;
   else
      return -1;
}
void sortBookT(){
	char authorName[8];
	char postC[2];
	strcpy(postC,"'");
	char Ifcontrol[] = "Author";
	printf("\tAuthor's Name\n");
	scanf("%s",authorName);
	if((strstr(authorName,Ifcontrol))==NULL){
	printf("\t No such author, pls enter such that \"Author1\"\n");
	sortBookT();
	return;
	}
	char cmd[23];
	char command[31];
	strcpy(cmd,"cat myLib.txt | grep '");
	strcpy(command,cmd);
	strcat(command,authorName);
	strcat(command,postC);
	puts("\tmatched");
	system(command);
	puts("\tcurrent record");
	system("cat myLib.txt");
	puts("\t t for try again or b for to main menu, 'any key' back to user page");
	char option;
    scanf(" %c",&option);
	if((option=='t') || (option=='b') )
		sortBookT();
	else{
		showMenuB();
		return ;
	}
	return;
};
void bookIn(){
	char authorName[7];
	char Ifcontrol[] = "Book";
	char postC[2];
	char postC1[79];
	char postC2[79];
	strcpy(postC,"'");
	strcpy(postC1," | grep 'null' | awk -F ',' '{print $1,$2\" available \"}'");
	strcpy(postC2," | grep '-' | awk -F ',' '{print $1,$2\" available \"$6}'");
	printf("\tBook's Name\n");
	scanf("%s",authorName);
	if((strstr(authorName,Ifcontrol))==NULL){
	printf("\t No such Book name, pls enter such that \"Book1\"\n");
	bookIn();
	return;
	}
	char cmd[99];
	char command[99];
	strcpy(cmd,"cat myLib.txt | grep '");
	strcpy(command,cmd);
	strcat(command,authorName);
	strcat(command,postC);
	strcat(command,postC1);
	puts("\t matched and available ");
	system(command);
	strcpy(cmd,"cat myLib.txt | grep '");
	strcpy(command,cmd);
	strcat(command,authorName);
	strcat(command,postC);
	strcat(command,postC2);
	system(command);
	
	puts("\t t for try again or b for to main menu, 'any key' back to user page");
	char option;
    scanf(" %c",&option);
	if((option=='t') || (option=='b') )
		bookIn();
	else{
		showMenuB();
		return ;
	}
	return;
};
void bookOut(){
	FILE *dateIn;
	int date;
	int out1,ret1,out2,ret2;
	int dy,dm,dd,wholeDay;
	//char currentDate[9];
	char uID[6];
	printf("\t enter a date such that: 2018-12-12 \n");
	scanf("%d-%d-%d",&dy,&dm,&dd);
	wholeDay=dy*10000+dm*100+dd;
	if(wholeDay<bookCheckOutConv||wholeDay>bookCheckRetConv){
	printf("\t date is invalid, try again!   \n");	
	bookOut();
	return;
	}
	//strcat(currentDate1,dateY); //strcat(currentDate1,dateM); //strcat(currentDate1,dateD);
	printf("\t enter the userID\n");
	scanf("%s",uID);
	char Ifcontrol[] = "User";
	if((strstr(uID,Ifcontrol))==NULL){
	printf("\t No such UserName, pls enter such that \"User1\"\n");
	bookOut();
	return;
	}
	date=wholeDay;

	char dateCheckOutUser1Book1[9];
	char dateCheckRetUser1Book1[9];
    dateIn=popen("cat myLib.txt | grep 'User1' | awk -F',' '{print $5}' | sed 's/-//g' | head -n 1","r");
	fgets(dateCheckOutUser1Book1,sizeof(dateCheckOutUser1Book1),dateIn);
	dateIn=popen("cat myLib.txt | grep 'User1' | awk -F',' '{print $6}' | sed 's/-//g' | head -n 1","r");
	fgets(dateCheckRetUser1Book1,sizeof(dateCheckRetUser1Book1),dateIn);

	char dateCheckOutUser1Book2[9];
	char dateCheckRetUser1Book2[9];
    dateIn=popen("cat myLib.txt | grep 'User1' | awk -F',' '{print $5}' | sed 's/-//g' | tail -n 1","r");
	fgets(dateCheckOutUser1Book2,sizeof(dateCheckOutUser1Book2),dateIn);
	dateIn=popen("cat myLib.txt | grep 'User1' | awk -F',' '{print $6}' | sed 's/-//g' | tail -n 1","r");
	fgets(dateCheckRetUser1Book2,sizeof(dateCheckRetUser1Book2),dateIn);	
	//printf(" CheckOut:%s-DueRet:%s\n CheckOut:%s-DueRet:%s \n",dateCheckOutUser1Book1,dateCheckRetUser1Book1,dateCheckOutUser1Book2,dateCheckRetUser1Book2);
	out1=atoi(dateCheckOutUser1Book1);ret1=atoi(dateCheckRetUser1Book1);
	out2=atoi(dateCheckOutUser1Book2);ret2=atoi(dateCheckRetUser1Book2);
	pclose(dateIn);
	printf("\tYou enterred date: %d-%d-%d\n",dy,dm,dd);
	printf("\tYou enterred userID: %s\n",uID);
	if(date>ret1){
		printf("\tOver Due\n");
		system("cat myLib.txt | grep 'User1' | head -n 1");
	}
	if(date>ret2){
		printf("\tOver Due\n");
		system("cat myLib.txt | grep 'User1' | tail -n 1");
	}	
	
	puts("\t t for try again or b for to main menu, 'any key' back to user page");
	char option;
    scanf(" %c",&option);
	if((option=='t') || (option=='b') )
		bookOut();
	else{
		showMenuB();
		return ;
	}
	return;
	
};
void addBook(){
	char title[11];puts("\t title of the book ");scanf("%s",title);
	char author[11];puts("\t author of the book ");scanf("%s",author);
	char bookIDChar[3];
	FILE *addBooks;
	addBooks=popen("cat myLib.txt | wc -l","r");
	fgets(bookIDChar,sizeof(bookIDChar),addBooks);
	bookID=(atoi(bookIDChar))+1;
	addBooks=fopen("myLib.txt","a+");
	fprintf(addBooks,"%d,%s,%s,library,null,null,\n",bookID,title,author);
	fclose(addBooks);

	puts("\t t for try again or b for to main menu, 'any key' back to user page");
	char option;
    scanf(" %c",&option);
	if((option=='t') || (option=='b') )
		addBook();
	else{
		showMenuL();
		return ;
	}
	return;
};
void delBook(){
	//printf("\t current bookID %d\n",bookID);
	char bookIDDelete[3];puts("\t Enter the book ID ");scanf("%s",bookIDDelete);
	char cmd[88] = "sed -i '/";
	int idDeleteConv;
	idDeleteConv=atoi(bookIDDelete);
	if(idDeleteConv<=0||idDeleteConv>bookID){
		printf("\t No such book\n");
		puts("\t t for try again or b for to main menu, 'any key' back to user page");
		char option;
		scanf(" %c",&option);
		if((option=='t') || (option=='b') )
			delBook();
		else{
			showMenuL();
			return ;
		}
	}
		strcat(cmd,bookIDDelete);
		strcat(cmd,",/d' myLib.txt");
		system(cmd);
		bookID--;
		puts("\t t for try again or b for to main menu, 'any key' back to user page");
		char option;
		scanf(" %c",&option);
		if((option=='t') || (option=='b') )
			delBook();
		else{
			showMenuL();
			return ;
		}
	return;
};
void checkOutBook(){
	char userName[6];puts("\t enter user name ");scanf("%s",userName);
	char Ifcontrol[] = "User";
	if((strstr(userName,Ifcontrol))==NULL){
	printf("\t No such User, pls enter such that \"User1\"\n");
	checkOutBook();
	return;
	}
	char numerbUserHas[2]; int numerbUserHasInt;FILE *checkOutBooks;
	char cmd[66] = "cat myLib.txt | grep '";strcat(cmd,userName);strcat(cmd,"' | wc -l");
	checkOutBooks=popen(cmd,"r");
	fgets(numerbUserHas,sizeof(numerbUserHas),checkOutBooks);
	fclose(checkOutBooks);
	numerbUserHasInt = atoi(numerbUserHas);
		if(numerbUserHasInt>=3){
				printf("\t %s cant get more than 3 books \n",userName);
				puts("\t t for try again or b for to main menu, 'any key' back to user page");
			char option;
			scanf(" %c",&option);
			if((option=='t') || (option=='b') )
			checkOutBook();
			else{
			showMenuL();
			return ;
		}
		}
	char bookIDDelete[3];puts("\t Enter the book ID ");scanf("%s",bookIDDelete);
	char cmd1[66] = "sed -i '/";
	int idDeleteConv;
	idDeleteConv=atoi(bookIDDelete);
	if(idDeleteConv<=0&&idDeleteConv>bookID){
		printf("\t No such book\n");
		puts("\t t for try again or b for to main menu, 'any key' back to user page");
		char option;
		scanf(" %c",&option);
		if((option=='t') || (option=='b') )
			checkOutBook();
		else{
			showMenuL();
			return ;
		}
	}
	char cmdCO[99] = "sed -i '"; strcat(cmdCO,bookIDDelete);strcat(cmdCO,"s/library/");
	strcat(cmdCO,userName);strcat(cmdCO,"/;");strcat(cmdCO,bookIDDelete);strcat(cmdCO,"s/null/");strcat(cmdCO,bookCheckOut);
												strcat(cmdCO,"/;");strcat(cmdCO,bookIDDelete);strcat(cmdCO,"s/null/");strcat(cmdCO,bookCheckRet);
												strcat(cmdCO,"/' myLib.txt");
	system(cmdCO);printf("\t Book ID: %d check out successfully\n",idDeleteConv);
		puts("\t t for try again or b for to main menu, 'any key' back to user page");
		char option;
		scanf(" %c",&option);
		if((option=='t') || (option=='b') )
			checkOutBook();
		else{
			showMenuL();
			return ;
		}
	return;
};
void retBook(){
	char bookIDDelete[3];puts("\t Enter the book ID ");scanf("%s",bookIDDelete);
	int idDeleteConv;idDeleteConv=atoi(bookIDDelete);
	if(idDeleteConv<0&&idDeleteConv>bookID)
		printf("No such book\n");
	else{
		//char currentDate[11]; 
		int currentDateConv;
		printf("\t enter current date \n");scanf("%d",&currentDateConv);
		//currentDateConv=atoi(currentDate);
		if(currentDateConv<bookCheckOutConv){
			printf("\t illegal date\n");
		}
		else{
				char cmdCOR[127] = "sed -ie '";
				strcat(cmdCOR,bookIDDelete);char exceptionsC[28] = "s/User1/library/;";strcat(cmdCOR,exceptionsC);	
				strcat(cmdCOR,bookIDDelete);strcat(cmdCOR,"s/");strcat(cmdCOR,bookCheckOut);strcat(cmdCOR,"/null/;");
				strcat(cmdCOR,bookIDDelete);strcat(cmdCOR,"s/");strcat(cmdCOR,bookCheckRet);strcat(cmdCOR,"/null/' myLib.txt");
				system(cmdCOR);		
			printf("\t Book ID:check Return successfully\n");
			puts("\t t for try again or b for to main menu, 'any key' back to user page");
			char option;
			scanf(" %c",&option);
			if((option=='t') || (option=='b') )
				retBook();
			else{
				showMenuL();
				return ;
			}
		}
	}
	return;
};
void checkUsers(){
	system("cat userInfo.txt");	
		puts("\t t for try again or b for to main menu, 'any key' back to user page");
	char option;
    scanf(" %c",&option);
	if((option=='t') || (option=='b') )
		checkUsers();
	else{
		showMenuL();
		return ;
	}
return;	
}
void addUsers(){
	char FN[8];puts("\t user frist name ");scanf("%s",FN);
	char LN[8];puts("\t user last name ");scanf("%s",LN);
	char AcctID[8];puts("\t account ID ");scanf("%s",AcctID);
	char AcctPW[8];puts("\t account password ");scanf("%s",AcctPW);
	char userIDChar[3];
	FILE *addUser;
	addUser=popen("cat userInfo.txt | wc -l","r");
	fgets(userIDChar,sizeof(userIDChar),addUser);
	userId=(atoi(userIDChar))+1;
	addUser=fopen("userInfo.txt","a+");
	fprintf(addUser,"%d,%s,%s,%s,%s,B\n",userId,FN,LN,AcctID,AcctPW);
	fclose(addUser);
	system("cat userInfo.txt");
	
	puts("\t t for try again or b for to main menu, 'any key' back to user page");
	char option;
    scanf(" %c",&option);
	if((option=='t') || (option=='b') )
		addUsers();
	else{
		showMenuL();
		return ;
	}
	return;
};
void delUsers(){
	char userIdDel[3];puts("\t Enter the user ID you want to delete ");scanf("%s",userIdDel);
	char cmd[66] = "sed -i '/";
	int idDeleteConv;
	idDeleteConv=atoi(userIdDel);
	if(idDeleteConv<0||idDeleteConv>userId){
		printf("\t No such user\n");
		puts("\t t for try again or b for to main menu, 'any key' back to user page");
		char option;
		scanf(" %c",&option);
		if((option=='t') || (option=='b') )
			delUsers();
		else{
			showMenuL();
			return ;
		}
	}
		strcat(cmd,userIdDel);
		strcat(cmd,",/d' userInfo.txt");
		system(cmd);
		userId--;
		puts("\t t for try again or b for to main menu, 'any key' back to user page");
		char option;
		scanf(" %c",&option);
		if((option=='t') || (option=='b') )
			delUsers();
		else{
			showMenuL();
			return ;
		}
	return;
};
void wrong(){
	return;
};
int main(int argc,char *argv[]){
	int loopControl =1;
	while(loopControl==1){
	printf("\t***Enter your log in info, pls***\n");
	printf("\tformat such that:First1,Last1,Acct1,1234\n");
	char logIn[25];char functionality;
	scanf("%s",logIn);
	if((compare_strings(logIn,user1B)==0)||(compare_strings(logIn,user2B)==0)){
		showMenuB();
		while((functionality=getchar())!='x'){
			if(functionality=='q'){sortBookT();}
				else if(functionality=='s'){bookIn();}
				else if(functionality=='u'){bookOut();}
				else wrong();
		}
	}
	 else if(compare_strings(logIn,user1L)==0){
		showMenuL();
		while((functionality=getchar())!='x'){
			if(functionality=='a'){addBook();}
				else if(functionality=='d'){delBook();}
				else if(functionality=='o'){checkOutBook();}
				else if(functionality=='r'){retBook();}
				else if(functionality=='c'){checkUsers();}
				else if(functionality=='u'){addUsers();}
				else if(functionality=='n'){delUsers();}
			else wrong();
		}
	}
	else
		printf("***No current user info***\n");
	
	}
	return EXIT_SUCCESS;
}

