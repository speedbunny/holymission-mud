short() { return "test"; }

init() { add_action("test","test"); }

test() {
int k;

  k=0;
  while(1) {
     k++;
     k%=18;
     write("k "+k+"\n");
  }

}

