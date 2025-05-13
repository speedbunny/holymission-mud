#define TPN this_player()->query_name()
inherit "obj/treasure";

status has_saddle, has_horn;

reset(arg){

has_saddle = 0;
has_horn = 0;

 if(arg) return 1;
     set_id("uni_stat");
     set_name("Horse statue");
     set_alias("horse");
     set_alt_name("statue");
     set_value(0);
     set_weight(1000);
     set_short("A life size horse statue");
     set_long(
"A stone horse statue that looks life like. There is a small "+
"round hole above its\neyes near the center of its head.\n");

   return 1;
}
can_get() { return 0; }

init(){
 ::init();

  add_action("_put", "put");
  add_action("_put", "place");
  add_action("no_ride", "ride");
  add_action("no_ride", "mount");
	}

no_ride(str){
  if(str == "horse" || str == "statue"){
    if(has_saddle){
	write("You feel foolish but ride the statue anyway.\n");
	say(TPN + " looks foolish riding the horse statue.\n");
	return 1;
		}
    else {
	write("The horse is not ready to be ridden.\n");
	return 1;
	}
     }
}
_put(){
object what;
string where;


  if(sscanf("%s on %s", what, where){
    if((where == "horse") || (where== "statue") || (where == "horse statue")){
   if(!present(what, this_player())){
	write("You do not have that.\n");
	return 1; }
   if(what=present("unicorn_saddle", this_player()) && ((where == "horse") || (where == "statue")){
    move_object(what, this_object());
    has_saddle = 1;
	desc(){ return "There is a saddle on the horse staue"; }

