#include<iostream>
#include<list>
#define MAX_CHAR 256
using namespace std;

//node of trie with all suffixes
class TrieNode
{
       private:
              TrieNode *children[MAX_CHAR];
              list<int> *indexes;
       public:
              // constructor
              TrieNode()
              {
                     // Creating an empty linked list for storing indexes of
                     // suffixes starting from the current node
                     indexes = new list<int>;


                     for (int i = 0; i < MAX_CHAR; i++)
                     {
                            children[i] = NULL; // initializing all child pointers as NULL
                     }
              }

              //  function to insert a suffix of the given txt
              // in subtree rooted with this node
              void insertSuffix(string suffix, int index)
              {
                     // Store index in linked list
                     indexes->push_back(index);

                     // If string has more characters
                     if (suffix.length() > 0)
                     {

                            char cIndex = suffix.at(0);// first character

                            //add a new edge if there is no edge for this character
                            if (children[cIndex] == NULL)
                                   children[cIndex] = new TrieNode();

                            // Recur for next suffix
                            children[cIndex]->insertSuffix(suffix.substr(1), index+1);
                     }
             }

              // A function for the pattern searching in subtree rooted
              // with this node which returns pointer to a linked
              // list containing all indexes where pattern is present.

              list<int>* search(string pat)
              {
                     // return the list of indexes if all characters of pattern is processed,
                     if (pat.length() == 0)
                            return indexes;

                     // if there is an edge for the current character, then follow the edge.

                     if (children[pat.at(0)] != NULL)
                            return (children[pat.at(0)])->search(pat.substr(1));

                     // pattern doesn’t exist in  the text If there is no edge,
                     else return NULL;
              }


};

//  trie of all suffixes
class TrieOfSuffixes
{
       private:
              TrieNode root;
       public:
              // constructing a trie of suffixes of the given text(constructor)
              TrieOfSuffixes(string txt)
              {
                     // inserting all suffixes into the Suffix Trie
                     //using the recursive function

                     for (int i = 0; i < txt.length(); i++)
                            root.insertSuffix(txt.substr(i), i);
              }

              // Function for searching a pattern in this suffix trie.
              int search(string pat)
              {

                     int cnt=0;
                     list<int> *result = root.search(pat);// calling  search function for root of Trie.

                     //  paattern not matched if the list of indexes is empty
                     if (result == NULL)
                            cout << "Pattern not found" << endl;
                     else
                     {
                    list<int>::iterator i;
                    int patLength = pat.length();
                    for (i = result->begin(); i != result->end(); i++)
                    {
                     cout << "Pattern found at position " << *i - patLength<< endl;
                     cnt++;

                    }

                     }
                     return cnt;
              }

};

bool defect(string org,string mut,string pattern)
{
    cout<<"\nThe original  DNA : "<<org;
    cout<<"\nThe mutated DNA : "<<mut;
    cout<<"\nSearch for the pattern \""<<pattern<<"\"";
    cout<<"\nCHECKING IN THE ORIGINAL DNA : ";
    TrieOfSuffixes S1(org);
    int t1=S1.search(pattern);

    cout<<"\nCHECKING IN THE MUTATED DNA : ";
    TrieOfSuffixes S2(mut);
    int t2=S2.search(pattern);

    if(t1==t2)
        return 0;
    else
        return 1;

}

void sickel()
{
    cout<<"NORMAL DNA :ATGGTGCACCTGACTCCTGAGGAGAAGTCTGCCGTTACT"<<endl;
    cout<<"MUTANT DNA:ATGGGGCACCTGACTCCTGTGGTGAAGTCTGCCGTTACT"<<endl;
    string txt1= "ATGGTGCACCTGACTCCTGAGGAGAAGTCTGCCGTTACT";
    cout<<"NORMAL DNA"<<endl;
    TrieOfSuffixes S(txt1);

    cout << "Search for 'GAG'" << endl;
    S.search("GAG");
    string txt2 = "ATGGGGCACCTGACTCCTGTGGTGAAGTCTGCCGTTACT";
    cout<<"MUTANT DNA"<<endl;
    TrieOfSuffixes S1(txt2);

    cout << "Search for 'GTG'" << endl;
    S1.search("GTG");
    cout<<"DISEASE: SICKLE CELL ANEMIA"<<endl;


}

void ferritin()
{
    cout<<"NORMAL DNA :ATGGTGCACCTGACTCCTGAGGAGAAGTCTGCCGTTACT"<<endl;
    cout<<"MUTANT DNA:ATGGTGCACCTGACTCCTTAGTAGAAGTCTGGGGTTACT"<<endl;
    string txt3 = "ATGGTGCACCTGACTCCTGAGGAGAAGTCTGCCGTTACT";
    cout<<"NORMAL DNA"<<endl;
    TrieOfSuffixes S3(txt3);

    cout << "Search for 'GAG'" << endl;
    S3.search("GAG");
    string txt4 = "ATGGTGCACCTGACTCCTTAGTAGAAGTCTGGGGTTACT";
    cout<<"MUTANT DNA"<<endl;
    TrieOfSuffixes S2(txt4);

    cout << "Search for 'TAG'" << endl;
    S2.search("TAG");
    cout<<"DISEASE: FERRITIN DEFICIENCY"<<endl;


}
void g6pd()
{
    cout<<"NORMAL DNA :ATGGTGCACCTGACTCCTCCGGAGAAGTCTGGGGTTACT"<<endl;
    cout<<"MUTANT DNA:ATGGTGCACCTGACTTCTTCGGAGAAGTCTGGGGTTACT"<<endl;
    string txt5= "ATGGTGCACCTGACTCCTCCGGAGAAGTCTGGGGTTACT";
    cout<<"NORMAL DNA"<<endl;
    TrieOfSuffixes S5(txt5);

    cout << "Search for 'TCC'" << endl;
    S5.search("TCC");
    string txt6 = "ATGGTGCACCTGACTTCTTCGGAGAAGTCTGGGGTTACT";
    cout<<"MUTANT DNA"<<endl;
    TrieOfSuffixes S6(txt6);

    cout << "Search for 'TTC'" << endl;
    S6.search("TTC");
    cout<<"DISEASE: G6PD DEFICIENCY"<<endl;


}

void beta()
{
    cout<<"NORMAL DNA :ATGGTGCACCTGACTCCTCCGGAGAAGTCTGGGGTTACT"<<endl;
    cout<<"MUTANT DNA:ATAGTGCACCTGACTCCTCCGGAGAAGTCTAGGGTTACT"<<endl;
    string txt7 = "ATGGTGCACCTGACTCCTCCGGAGAAGTCTGGGGTTACT";
    cout<<"NORMAL DNA"<<endl;
    TrieOfSuffixes S7(txt7);

    cout << "Search for 'TGG'" << endl;
    S7.search("TGG");
    string txt8 = "ATAGTGCACCTGACTCCTCCGGAGAAGTCTAGGGTTACT";
    cout<<"MUTANT DNA"<<endl;
    TrieOfSuffixes S8(txt8);

    cout << "Search for 'TAG'" << endl;
    S8.search("TAG");
    cout<<"DISEASE: BETA THALASSEMIA"<<endl;


}

// driver code
int main()
{
// suffix trie for text "minimize"
     string dna3="GAG CCA TTA CAT GAA CGA TGA AAG GCC CAA GTT TAT CAG";
     string dna4="ATT CAA CTC CAA CTC ATG CAG CGA TTA GCC TAT CAG GAG";

     string dna3_a="GAG CCA TTA CAT GAA CGA TGA AAG GCC CAA GTT TGT CAG";
     string dna3_b="GAG CCA TTA CAT GAA CGA TGA AAG GCC TAA GTT TAT CAG";
     string dna3_c="GAG CCA TTA CAT GAA CGA TGA AAG GCC CAA GTT TAT TAG";
     string dna3_d="GAG CCA TTA CAT GAA TGA TGA AAG GCC CAA GTT TAT CAG";

     string dna4_a="ATT CAA CTC CAA CTC ATG CAG CGA TTA GCC TGT CAG GAG";
     string dna4_b="ATT TAA CTC TAA CTC ATG CAG CGA TTA GCC TAT CAG GAG";
     string dna4_c="ATT CAA CTC CAA CTC ATG TAG CGA TTA GCC TAT TAG GAG";
     string dna4_d="ATT CAA CTC CAA CTC ATG CAG TGA TTA GCC TAT CAG GAG";

     int choice1,choice2;
     bool d_b;
     cout<<"\n1. ATG GTG CAC CTG ACT CCT GAG GAG AAG TCT GCC GTT ACT"<<endl;
     cout<<"2. ATG GTG CAC CTG ACT CCT CCG GAG AAG TCT GGG GTT ACT";
     cout<<"\n3. "<<dna3<<"\n4. "<<dna4;
     cout<<"\nChoose any one of the original DNA sequence (from above) : ";
     cin>>choice1;
     if(choice1==1)
        {
            cout<<"CHOOSE THE MUTANT DNA"<<endl;
            cout<<"1. ATG GGG CAC CTG ACT CCT GTG GTG AAG TCT GCC GTT ACT"<<endl;
            cout<<"2. ATG GTG CAC CTG ACT CCT CCG TAG AAG TCT GGG GTT ACT"<<endl;
            cin>>choice2;
            if(choice2==1)
            {
                sickel();
            }
            if(choice2==2)
            {
                ferritin();
            }
        }
        if(choice1==2)
        {
            cout<<"CHOOSE THE MUTANT DNA"<<endl;
            cout<<"1. ATG GTG CAC CTG ACT TCT TCG GAG AAG TCT GGG GTT ACT"<<endl;
            cout<<"2. ATA GTG CAC CTG ACT CCT CCG GAG AAG TCT AGG GTT ACT "<<endl;
            cin>>choice2;
            if(choice2==1)
            {
                g6pd();
            }
            if(choice2==2)
            {
                beta();
            }
        }
     if(choice1==3)
     {
            cout<<"\n1. "<<dna3_a<<"\n2. "<<dna3_b<<"\n3. "<<dna3_c<<"\n4. "<<dna3_d<<"\n5. "<<dna3;
            cout << "\nEnter any one of the mutated-DNA to check the mutation type : ";
            cin>>choice2;
            if(choice2==1)
            {
                d_b=defect(dna3,dna3_a,"TGT");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TGT\" positions\nThis Mutated DNA has Dyserythropoietic anemia -- blood disorder."<<endl;
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==2)
            {
                d_b=defect(dna3,dna3_b,"TAA");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TAA\" positions\nThis Mutated DNA has Hemophilia B -- blood disorder.";
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==3)
            {
                d_b=defect(dna3,dna3_c,"TAG");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TAG\" positions\nThis Mutated DNA has Fanconi anemia -- blood disorder.";
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==4)
            {
                d_b=defect(dna3,dna3_d,"TGA");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TGA\" positions\nThis Mutated DNA has Von Willebrand -- blood disorder.";
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==5)
            {
                d_b=defect(dna3,dna3,"CAG");
                if(d_b==0)
                    cout<<"\nNo blood disorder!";
            }
     }
     if(choice1==4)
     {
            cout<<"\n1. "<<dna4_a<<"\n2. "<<dna4_b<<"\n3. "<<dna4_c<<"\n4. "<<dna4_d<<"\n5. "<<dna4;
            cout << "\nEnter any one of the mutated-DNA to check the mutation type : ";
            cin>>choice2;
            if(choice2==1)
            {
                d_b=defect(dna4,dna4_a,"TGT");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TGT\" positions\nThis Mutated DNA has Dyserythropoietic anemia -- blood disorder."<<endl;
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==2)
            {
                d_b=defect(dna4,dna4_b,"TAA");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TAA\" positions\nThis Mutated DNA has Hemophilia B -- blood disorder.";
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==3)
            {
                d_b=defect(dna4,dna4_c,"TAG");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TAG\" positions\nThis Mutated DNA has Fanconi anemia -- blood disorder.";
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==4)
            {
                d_b=defect(dna4,dna4_d,"TGA");
                if(d_b==1)
                    cout<<"\nThe original DNA and mutated DNA have different \"TGA\" positions\nThis Mutated DNA has Von Willebrand -- blood disorder.";
                else
                    cout<<"\nNo blood disorder!"<<endl;
            }
            else if(choice2==5)
            {
                d_b=defect(dna4,dna4,"CAG");
                if(d_b==0)
                    cout<<"\nNo blood disorder!";
            }
     }
    cout<<endl;
    return 0;
}
