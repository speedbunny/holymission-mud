object shadowee;

start_shadow(ob) {
  shadow(ob, 1);
  shadowee=ob;
}

eat_food() {
  write("You feel too ill to eat anything.\n");
  return 0;
}

drink_alcohol() {
  write("You feel too ill to drink anything.\n");
  return 0;
}

drink_soft() {
  write("You feel too ill to drink anything.\n");
  return 0;
}

heal_self(i) {
  return shadowee->heal_self(i/2);
}
