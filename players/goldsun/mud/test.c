inherit "/room/room";

void reset(int flag) {
  if (!flag) {
    short_desc = "Testmeadow";
    long_desc  =
      "It should look like you are on a grassy meadow.\n";
    set_light(1);
    items = ({
      "heaven","The heaven is blue"
      });
  }
}

init() {
  ::init();
  add_action("light","light");
}

light(){
  object p,fl;
  int psiz, j;

  p=all_inventory(this_object());
  psiz=sizeof(p);
  for(j=0;j<psiz;j++) {
    if (living(p[j]) && !(p[j]->query_npc())){
     fl=clone_object("/players/goldsun/fl");
     transfer(fl,p[j]);
     fl->doharha();           
    }
  }
  return 1;
}

