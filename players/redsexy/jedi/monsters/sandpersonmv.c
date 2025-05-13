inherit "obj/monster";
int count;

void reset( int arg) 

{

::reset(arg);



if (arg) return;

set_name("sandperson");

set_alt_name("sandman");

set_race("human");

set_short("Sandperson");

set_long("This is one of the sandpeople who are notorious fighters and\n"

       + "easy to anger. They roam the desert lands with a\n"

       + "minimum of resources, unafraid of who they encounter.\n");  

set_gender(1);

set_level(25);

add_money(1000);
}


heart_beat() {
  if(++count>4) {
   random_move();
   count=0;
}
::heart_beat();
}
