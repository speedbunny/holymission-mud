/* Coded by Blade on Holy Mission */
/* simple shadow cloner           */

object sh;
object mon;

id(str) { return str=="sh"; }

short(){return "sh";}

get() { return 1; }

init() {
     add_action("start","start");
}

int start(string monster_name) {

 if(mon=present(monster_name)){
    sh=clone_object("/players/tatsuo/area/monster_shadow");
    sh->start_shadow(mon);
  }
    return 1;
}

