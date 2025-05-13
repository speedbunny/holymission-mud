inherit "/obj/treasure";

reset(arg){
 if (arg) return;
 set_id("scroll");
 set_read(
  "    DESCRIPTION         |    COMMMAND\n\n"+
  "  get a treasury chest  :   'chest'\n"+
  "  to bring your chest\n"+
  "   and unlock it        :   'bring chest'\n"+
  "  to lock and carry off\n"+
  "   your chest           :   'carry off chest'\n"
         );
 set_short("A scroll");
 set_long("An old scroll.\n");
 set_weight(0);
 set_value(0);
 }

int drop(){
 write("The scroll crumblest to the dust.\n");
 destruct(this_object());
 return 1;
}
