id(str){return str=="whohas";}
short(){return "a whohasser";}
get(){return 1;}
drop(){return 1;}
long(){write("Usage: cwhohas <creator>\n");}
init(){add_action("wh","cwhohas");}
wh(str){object *poss; int i,j;
  for (i=0;i<sizeof(users());i++){
   poss=filter_array(all_inventory(users()[i]),"get_creator",this_object(),str);
  for(j=0; j<sizeof(poss);j++)
    write(users()[i]->query_real_name()+": "+
     (poss[j]->short() ? poss[j]->short() : "<INVIS>")+
    "  "+file_name(poss[j])+"\n");
  }
  return 1;
}
get_creator(ob,wizard){return creator(ob)==wizard;}
