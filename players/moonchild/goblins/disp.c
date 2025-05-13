object g1,g2,g3,g4;

make() {
  if(!g1) move_object(g1=clone_object("players/moonchild/goblins/goblin"),"room/south/sforst1");
  if(!g2) move_object(g2=clone_object("players/moonchild/goblins/goblin"),"room/forest7");
  if(!g3) move_object(g3=clone_object("players/moonchild/goblins/goblin"),"room/forest8");
  if(!g4) move_object(g4=clone_object("players/moonchild/goblins/redgob"),"room/mine/tunnel20");
}
more() { call_out("make", 300, 0); }

