#include <iostream>
using namespace std;


#include "foo.h"
#include "bar.h"

int main()
{
  Foo *foo = new Foo(0,1);
  Bar *bar = new Bar(2,3);

  foo->print();
  bar->print();
}
