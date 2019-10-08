#include<bits/stdc++.h>
using namespace std;
string encryption(string plain,string key,int userkey)
{
	string out;
	for(long long int i=0,j=0;i<plain.size();i++)
	{
		char c=plain[i];
		if(plain[i]>96 && plain[i]<123)
		{
			c=((plain[i]-97+key[j]-97+userkey)%51);
			if(c>=0 && c<=25)
			out+=c+97;
			if(c>=26 && c<=35)
			out+=c+'0'-26;
			if(c>=36 && c<=50)
			out+=c+33-36;
		}
		else if(plain[i]>47 && plain[i]<59)
		{
			c=((plain[i]-48+26+key[j]-97+userkey)%51);
			if(c>=0 && c<=25)
			out+=c+97;
			if(c>=26 && c<=35)
			out+=c+'0'-26;
			if(c>=36 && c<=50)
			out+=c+33-36;
		}
		else if(plain[i]>32 && plain[i]<48)
		{
			c=((plain[i]-33+36+key[j]-97+userkey)%51);
			if(c>=0 && c<=25)
			out+=c+97;
			if(c>=26 && c<=35)
			out+=c+'0'-26;
			if(c>=36 && c<=50)
			out+=c+33-36;
		}
		else
		continue;
		j = (j + 1) % key.length();
	}
	return out;
}
string decryption(string encrypt,string key,int userkey)
{
	string put;
	for(long long int i=0,j=0;i<encrypt.size();i++)
	{
		char c=encrypt[i];
		if(encrypt[i]>96 && encrypt[i]<123)
		{
			c=((encrypt[i]-97-key[j]+97-userkey+51)%51);
			if(c>=0 && c<=25)
			put+=c+97;
			if(c>=26 && c<=35)
			put+=c+'0'-26;
			if(c>=36 && c<=50)
			put+=c+33-36;
		}
		else if(encrypt[i]>47 && encrypt[i]<59)
		{
			c=((encrypt[i]-48+26-key[j]+97-userkey+51)%51);
			if(c>=0 && c<=25)
			put+=c+97;
			if(c>=26 && c<=35)
			put+=c+'0'-26;
			if(c>=36 && c<=50)
			put+=c+33-36;
		}
		else if(encrypt[i]>=32 && encrypt[i]<48)
		{
			c=((encrypt[i]-33+36-key[j]+97-userkey+51)%51);
			if(c>=0 && c<=25)
			put+=c+97;
			if(c>=26 && c<=35)
			put+=c+'0'-26;
			if(c>=36 && c<=50)
			put+=c+33-36;
		}
		else
		continue;
		j = (j + 1) % key.length();
	}
	return put;
}

int main()
{
	string plain,key;
	long long int userkey;
	cout<<"enter the plain text"<<endl;
	getline(cin,plain);
	cout<<endl<<"enter the key"<<endl<<endl;
	cin>>key;
	cout<<endl<<"enter the user key(any number)"<<endl<<endl;
	cin>>userkey;
	userkey%=26;
	string encrypt=encryption(plain,key,userkey);
	cout<<endl<<"encryption text:"<<encrypt<<endl;
	int choice;
	cout<<endl<<"press 1 for decryption"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			string decrypt=decryption(encrypt,key,userkey);
			cout<<endl<<"decryption text:"<<decrypt<<endl;
			break;
	}
	return 0;
}
