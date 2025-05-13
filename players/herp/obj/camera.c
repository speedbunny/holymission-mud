/* camera.c 910612 Herp --- Camera Obscura */
 
#define is_wiz(ob) (ob->query_level()>19)
#define owner_dir "/players/herp/obj"
#define pic_dir	  owner_dir + "/pics"
 
string fnames;
object player_ob,cat_obj;

init() { add_action("show_to","show"); }
 
reset(arg) {
  if (!arg) fnames = ({
    "01sex","02police","03dragon","04heart","05bunny",
    "06rebel","07bye","08bigbro","09like","10nuke",
    "11finger","12bad","13love","14ghost","15vmsg",
    "16go_away","17kiss","18beer","19darth","20gumby",
    "21hello","22kiss","23beer","24sleep","25heart",
    "26universe","27valmap","28hi","29bunny","30ice",
    "31relax","32skier","33smile","34irish","35spam",
    "36nuked","37self","38idea","39head","40dir",
    "41ibm","42pirate","43enter","44hi","45coke",
    "46action","47ghost","48xmas","49gun","50frog",
    "51long","52pres","53jerry","54term", "55mume"
  });
}
 
id(str) { if (str=="camera") return 1; }
 
get() { return 1; }
 
query_value() { return 100; }
 
short() { return "Camera Obscura"; }
 
long() {
  write("What a nice camera, you are delighted !\n");
  write("Maybe you want to show the camera to someone ?\n");
  write("Or just show a single picture ?\n");
}
 
show_to(str) {
string who,what;
int num;
 
  if (!str) return;
 
  who = "";
  num = 0;
 
  if (!present(this_object(),this_player())) {
     write("You must get it first !\n");
     return 1;
  }
 
  if (sscanf(str,"camera%s",what)==1) {
     if (sscanf(what," to %s",who)!=1) {
        write("show camera to whom ?\n");
        return 1;
     }
  }
 
  if (sscanf(str,"picture%s",what)==1) {
     if (sscanf(what," %d to %s",num,who)!=2) {
        write("show picture nr to whom ?\n");
        return 1;
     }
  }
 
  if (who=="") return 0;
 
  if (who=="me") player_ob=this_player();
  else {
 
     if (!(player_ob=find_player(who))) {
        write("No player with that name.\n");
        return 1;
     }
 
     if (environment(this_player())!=environment(player_ob)) {
         write("No such person present !\n");
         return 1;
     }

     if (!is_wiz(this_player()) && is_wiz(player_ob)) 
     {
           write(player_ob->query_name()+" wouldn't be very delighted ...\n");
           return 1;
     }
  }
 
  if (num) { show_pic(num); return 1; }
 
  cat(pic_dir+"/00menu.pic");
  input_to("get_num");
  return 1;
}
 
get_num(str) {
int num;
 
 if (!sscanf(str,"%d",num)) {
    write("Please enter a Number !\n");
    input_to("get_num");
    return 1;
 }
 return show_pic(num);
}
 
show_pic(i) {
 
 if (!i) return 1;
 
 if (i>55) {
    write("Please enter a valid number (1-55) !\n");
    return 1;
 }
 
 i=i-1;
 
 if (this_player()!=player_ob) {
 tell_object(player_ob,this_player()->query_name()+" shows you " +
  this_player()->query_possessive() + " Camera Obscura.\n");
 say(this_player()->query_name()+" shows " +
  this_player()->query_possessive() + " Camera Obscura to " +
  player_ob->query_name() + ".\n",player_ob);
 }
 else say(this_player()->query_name() + " looks into " +
          this_player()->query_possessive() + " Camera Obscura.\n");
 cat_obj=clone_object(owner_dir+"/cat_obj");
 move_object(cat_obj,player_ob);
 command("cat "+pic_dir+"/"+fnames[i]+".pic",player_ob);
 tell_object(player_ob,"You are impressed !\n");
 if (this_player()!=player_ob) write(player_ob->query_name()+
                             " looks quite impressed !\n");
 say(player_ob->query_name()+" looks quite impressed !\n",player_ob);
 return 1;
}
