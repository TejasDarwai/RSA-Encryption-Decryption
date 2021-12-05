/******************************************************************************

                         Rivest-Shamir-Adleman
                        Encryption - Decryption

*******************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int isPrime(int n){
  int flag = 1;
  for(int i=2;i<=sqrt(n);i++)
  {
      if(n%i==0)
      {
          flag = 0;
          return flag;
      }
  }
  return flag;
}

int gcd(int a, int b)  
 {  
   
    if (a == 0 || b == 0)  
        return 0;  
   
       
    if (a == b)  
        return a;  
   
   
    if (a > b)  
        return gcd(a-b, b);  
    return gcd(a, b-a);  
}

int lcm(int a, int b){  
    return (a*b)/gcd(a, b);  
} 

int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
       
        int q = a / m; 
        int t = m; 
  
       
        m = a % m, a = t; 
        t = y; 
  
       
        y = x - q * y; 
        x = t; 
    } 
  
    
    if (x < 0) 
       x += m0; 
  
    return x; 
}

int modular(int base, unsigned int exp, unsigned int mod)
{
    int x = 1;
    int i;
    int power = base % mod;

    for (i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}


int main(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;
    cout<<"               -----------------------------------------------------"<<endl;
    cout<<"               -                                                   -"<<endl;
    cout<<"               -   Rivest-Shamir-Adleman Encryption - Decryption   -"<<endl;
    cout<<"               -                                                   -"<<endl;
    cout<<"               -----------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;
    cout<<"                             Enter Message"<<endl;
    cout<<endl;
    cout<<"==>>";
    string message;
    vector<int> convertedmessage;
    vector<long long int> encryptedmessage;
    vector<long long int> decryptedmessage;
    getline(cin, message);
    for(int i=0; i<message.size(); i++){
        if(message[i] - '0' >=0 && message[i] - '0'<=9){
            convertedmessage.push_back(message[i] - '0');
        }
        else if(message[i] >= 'a' && message[i] <= 'z'){
            int temp = int(message[i]);
            convertedmessage.push_back(temp);
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            int temp = int(message[i]);
            convertedmessage.push_back(temp);
        }
        else if(message[i]==' '){
            convertedmessage.push_back(32);
        }
    }
    cout<<"==>> Converted Message"<<endl;
    for(int i=0; i<convertedmessage.size(); i++){
        cout<<convertedmessage[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"                            Encryption Phase"<<endl;
    cout<<endl;
    int p, q;
    int random;
    srand (time(NULL));
    int i=0;
    int a[2];
    generate:
    while(i<2){
        random = rand() % 40 + 3;
        if(isPrime(random)){
            a[i]=random;
            i++;
        }
      
    }
    i=0;
    p=a[0];
    q=a[1];
    if(p==q){
        goto generate;
    }

    cout<<"The two random prime numbers are: "<<p<<" and "<<q<<endl;
    
    int n;
    n = p*q;
    int phi = (p-1)*(q-1);
    int lambda = lcm(p-1,q-1);
    int e;
    vector<int> tot;
    for(int l=3;l<lambda;l++)
    {
        
        if(gcd(l,lambda) == 1){
            tot.push_back(l);
            
        }
    }
    int sizee = tot.size();
    int ran = rand() % sizee;
    e = tot[ran];
    long long int d = modInverse(e,lambda);
    if(d==e){
        cout<<endl<<endl<<"Waiting......"<<endl<<endl<<"Regenerating e and d"<<endl<<endl;
        goto generate;
    }
    
    cout<<"e==>>"<<e<<endl;
    cout<<"d==>>"<<d<<endl;

    for(int x=0; x<convertedmessage.size(); x++){
        long long int encrypt;
        encrypt = modular(convertedmessage[x],e,n);
        encryptedmessage.push_back(encrypt);

    }
    cout<<endl;
    
    for(int x=0; x<encryptedmessage.size(); x++){
        cout<<encryptedmessage[x]<<" ";
    }
    cout<<endl;
    cout<<"==>> Encrypted Message"<<endl;
    for(int x=0; x<encryptedmessage.size(); x++){
        cout<<(char)encryptedmessage[x];
    }
    cout<<endl;
    cout<<endl;
    cout<<"                            Decryption Phase"<<endl;
    cout<<endl;
    cout<<endl<<"Waiting..."<<endl<<"Decrypting Message"<<endl<<endl;
    for(int y=0; y<encryptedmessage.size(); y++){
        long long int decrypted;
        decrypted = modular(encryptedmessage[y],d,n);
        decryptedmessage.push_back(decrypted);
    }

    for(int z=0; z<decryptedmessage.size(); z++){
        cout<<decryptedmessage[z]<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Decrypted Message==>> ";
    for(int s=0; s<decryptedmessage.size(); s++){
        if(decryptedmessage[s]>=0 && decryptedmessage[s]<=9){
            cout<<decryptedmessage[s];
           
        }
        else{
            cout<<(char)decryptedmessage[s];
        }
    }
    cout<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    return 0;
}