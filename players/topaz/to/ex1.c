_gendershout( str ) {
object *u;
int i;

if(!str) {
    write("Shout what to all " + TP->query_gender_string()+ "s?\n");
    return (1);
}
if(!(TP->query_wizard()) && TP->query_sp() < 20) {
    write("You don't have enough spellpoints.\n");
}
else {
    write("You shout to all " + TP->query_gender_string() + "s:\n    " + str + "\n" );

    log_file("PLAYSHOUTS", TP->query_real_name()+": "+TP->query_name() + " shouts to all " + TP->query_gender_string() + "s:\n    " + str + "\n\n");
    u = users();

    for(i=0;i<sizeof(u);i++) {
      if(u[i]->query_gender_string() == TP->query_gender_string() && u[i] != TP) {
        tell_object(u[i], TP->query_name() +
          " shouts to all " + TP->query_gender_string() + "s:\n    " + str + "\n");
      }
      else if(TP !=u[i]) {
        tell_object(u[i],TP->query_name() + " shouts something in that unintelligible way that all " + TP->query_gender_string() + "s can shout.\n");
      }
    }
    if(!TP->query_wizard()) {
      TP->restore_spell_points(-20);
    }
    }
    return(1);
}
