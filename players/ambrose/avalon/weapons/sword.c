inherit "obj/weapon";

reset(arg){
if (arg) return;

  set_name("Sword");
  set_id("sword");
  set_short("sword");
  set_long("This finely made longsword has some writing on it.\n");
  set_value(1000);
  set_weight(5);
  set_class(13);
  set_read("Property of the Kingdom of Avalon.\n");
}
