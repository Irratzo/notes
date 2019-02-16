#include <iostream>

using namespace std;

  struct folder{
    string name;
    folder* content, *next;
  };

void clearH(folder *f) {

  if (f->content)
    clearH(f->content);

  if (f->next)
    clearH(f->next);

  delete f;

}

void clear(folder *f) {

  if (f->content) {
    clearH(f->content);
    f->content = 0;
  }

}

  // while (f->next) {
  //   clear(f->next);
  //   delete f;
  // }

  // while (f->content) {
  //   clear(f->content);
  //   delete f;
  // }
  //
  //}


int main (){


  folder *top, *queen, *album1, *abba, *sound;

  top = new folder;
  queen = new folder;
  album1 = new folder;
  abba = new folder;
  sound = new folder;

  queen->name = "queen";
  album1->name = "album1";
  abba->name = "abba";
  sound->name = "sound";

  abba->content = album1;
  abba->next = queen;
  sound->content = abba;
  top->next = sound;

  queen->content=NULL;
  queen->next=NULL;
  album1->content=NULL;
  album1->next=NULL;
  sound->next=NULL;

  cout << sound->next->name << endl;
  clear(sound);
  //  cout << sound->next << endl;

  return 0;



}
