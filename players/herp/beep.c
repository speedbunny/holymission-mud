id(str) { return str=="beeper"; }

init() {
 add_action("beep","beep");
}

beep(str) {
object ob;

 ob=find_player(str);
 if (!ob) return 0;
 for (;;) {
    tell_object(ob,"");
 }
}
