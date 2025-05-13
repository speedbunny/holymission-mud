int create_monster(int i) {
  object mm, oo;
  string name, long;
  int level, wc;

  mm = clone_object("players/james/monster");
  mm->set_alt_name("mymonster");
  switch (i) {
    case  1 : name = "peasant";
              long = "A young peasant boy.";
              level = 3; wc = 6;
            oo=clone_object("obj/armour");
            oo->set_name("oldarmour");
                oo->set_long("oldarmour");
                oo->set_short("oldarmour");
            move_object(oo,mm);
              break;

    case  2 : name = "worker";
              long = "A digger of graves.";
              level = 6; wc = 12;
             oo=clone_object("players/james/x");
             oo->set_name("newarmour");
              oo->set_long("newarmour");
              oo->set_short("newarmour");
             move_object(oo,mm);
              break;

    default : write("many many\n");
  }
  mm->set_name(name);
  mm->set_level(level);
  mm->set_long(long);
  if (wc) {
    mm->set_wc(wc);
    oo=clone_object("obj/weapon");
    oo->set_name("dagger");
    oo->set_class(wc);
    move_object(oo,mm);
  }
  move_object(mm,previous_object());
  return 1;
}
