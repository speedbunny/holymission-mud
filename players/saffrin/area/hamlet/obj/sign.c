inherit "/obj/thing";
 
void reset(int flag) {

  ::reset(flag);
  if (flag == 0) {
      set_name("sign");
      set_short("An important sign.  Please read it!");
      set_long("There is something written on it.\n");
      set_read(
        "        WARNING!!!!!               \n"+
        "Be warned that if you enter this theatre\n"+
        "you will fight for your life.  This area is\n"+
        "not suggested to be entered by low level\n"+
        "players.  You may want to try it in groups\n"+
        "Level 20 or higher at least!\n"+
        "You have been warned.\n"+
        " \n"
        "Saffrin.\n");
  }
}

int get(){
        return 0;
}
