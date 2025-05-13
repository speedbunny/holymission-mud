inherit "room/room";
object a,b,c,d,e,f;

reset (arg) {
if (!a) {
a=clone_object("obj/treasure");
transfer(a,this_object());
a->set_id("diamond");
a->set_short("diamond");
a->set_long("A rather pretty rdiamond.\n");
a->set_weight(1);
a->set_value(200);
}
if (!b) {
b=clone_object("obj/treasure");
transfer(b,this_object());
b->set_id("gem");
b->set_short("gem");
b->set_long("A beautiful red and purple gem.\n");
b->set_weight(1);
b->set_value(200);
}
if (!c) {
c=clone_object("obj/weapon");
transfer(c,this_object());
c->set_name("short-sword");
c->set_short("short-sword");
c->set_long("A short-sword.  It looks old.\n");
c->set_ac(3);
c->set_value(400);
c->set_weight(2);
}
if (!d) {
d=clone_object("obj/treasure");
transfer(d,this_object());
d->set_id("gold bar");
d->set_short("gold bar"); 
d->set_weight(3);
d->set_value(500);
}
if (!e) {
e=clone_object("obj/treasure");
transfer(e,this_object());
e->set_id("crown");
e->set_short("golden crown");
e->set_long("A beautiful crown with small rubies embedded in it.\n");
e->set_weight(2);
e->set_value(600);
}
if (!f) {
f=clone_object("obj/treasure");
transfer(f,this_object());
f->set_id("trident");
f->set_short("trident");
f->set_long("A pretty gold trident.\n");
f->set_weight(3);
f->set_value(500);
}
if (arg) return;
set_light(3);
short_desc = "treasury";
long_desc = "This is the goblin treasury.\n"
          + "The walls are made of thick stone, and the floor of pure red stone.\n"
          + "There are many riches in here.\n";
}
