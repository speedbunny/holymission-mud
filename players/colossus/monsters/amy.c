inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_short("Amy the beautiful");
    set_name("amy");
    set_race("human");
    set_long(
      "This is Amy, the love of my life. She has shoulder length dark\n"+
      "black, and soft hair. Her eyes are large and expressive and\n"+
      "seem to draw you deep into them. Her smile is enough to light\n"+
      "any dark room and her face is shaped like a heart.\n");
    set_level(10);
    set_hp(1000000000);
    set_ac(100000);
}
