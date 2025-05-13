inherit "/obj/armour";
void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  switch(random (3)) {
    case 0:
      set_name("leather armour");
      set_short("A leather armour");
      set_long("This leather armour offers you some protection.\n");
      set_ac(3);
      set_value(125);
      set_weight(2);
      break;
    case 1:
      set_name("chainmail");
      set_short("Draconian chainmail");
      set_long("Some draconian chainmail.\n");
      set_ac(4);
      set_value(500);
      set_weight(4);
      break;
    case 2:
      set_name("platemail");
      set_short("Draconian platemail");
      set_long("Some draconian platemail.\n");
      set_ac(4);
      set_value(500);
      set_weight(4);
      break;
  }
}
