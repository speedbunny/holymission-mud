/* added by Llort 020293 */
rescue(arg) {
  object whom;
  notify_fail("Rescue whom ?\n");
  if(arg && whom=present(arg,environment(this_player()))) {
      if(!whom->query_attack()) {
          notify_fail(whom->query_name()+" is not fighting.\n");
      } else{
          if(random(100)<30+(2*this_player()->query_level())) {
              tell_object(whom,this_player()->query_name()+
                          " heroically rescues you.\n");
              say(this_player()->query_name()+
                          " heroically rescues "+whom->query_name()+".\n",whom);
              whom->query_attack()->change_attacker(this_player());
              whom->stop_fight();
              whom->stop_fight();
          } else {
              write("The monster pays no attention to your attempt.\n");

          }
          return 1;
      }
  }
}
