int main(string str) {
  
  object *u;
  object pgs;    //The players guild soul.
  int num, i, sz;
  string msg, pret;
  
  if (!str) {
    write("=-=-=-=-=-=-=-=-=-=-=-=-=-= "+
          "Thieves online "+
          "=-=-=-=-=-=-=-=-=-=-=-=-=-= \n");
    u=users();
    msg="\n";
    num=0;
    sz=sizeof(u);
    for (i=0;i<sz;i++) {
      if (u[i]->thief_object()) {
        pret=u[i]->query_pretitle();
        pgs = u[i]->query_guild_soul();
        if(pgs->query_renegade()){
          pret="Renegade Thief";
        }
        if(pgs->query_righteous() && u[i]->query_real_name() != "brainsprain"){
          pret="Thief Guide";
        }
        if (pret=="") {
          if (u[i]->query_real_name()=="brainsprain")
            pret="Guild Master";
          else{
            switch(u[i]->query_level()) {
            case 1..5: pret="Neophyte Thief"; break;
            case 6..10: pret="Rogue"; break;
            case 11..15: pret="Burglar"; break;
            case 16..20: pret="Thief"; break;
            case 21..25: pret="Expert Thief"; break;
            case 26..29: pret="Shadow Master"; break;
            default: pret="Visiting Wizard"; break;         
            }
          }
        }
        msg=msg+sprintf("%20s %s\n",
                        pret,
                        capitalize(u[i]->query_real_name()));
        num++;
      }
    }
    write(msg+"\nThere are "+num+" thieves online.\n");
    return 1;
  }
  this_player()->guild_line(str);
  return 1;
}








