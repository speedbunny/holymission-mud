inherit "players/ted/items/food";

reset(arg) {
  if(arg) return;
  set_name("prickly pear");
  set_alias("pear");
  set_short("A Prickly Pear");
  set_long("This prickly pear looks juicy and delicious!\n");
  set_heal(15);
  set_mess("Prickly pear juices run down your face\nYum! Yum!\n");
  set_weight(1);
  set_value(10);
}
