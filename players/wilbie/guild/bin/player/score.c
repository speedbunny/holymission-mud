#include <sys_defs.h>

int main(string str) {
  string size,stat,victim,ret,cn,loc;
  string religion,prot_msg,tmp;
  int ac,got,lg,xp,sw,imm,max_hp;
  object att_ob,tp;

  tp=TP;
  imm=(tp->IMM || tp->TESTP);

  if(str && imm) {
    tp=find_player(str);
    if(!tp) {
      notify_fail(capitalize(str)+" is not playing now.\n");
      return 0;
    }
  }

  lg=tp->query_legend_level();
  xp=tp->query_exp();
  cn=tp->CRNAME;
  max_hp=tp->query_max_hp();
  ac=tp->query_ac();
  if(imm) {
    loc=file_name(environment(tp));
    if(loc[0..7]=="players/")
      loc="~"+loc[8..<1];
  }

  switch(ac) {
    case 0:
      prot_msg="none";
      break;
    case 1..3:
      prot_msg="bad";
      break;
    case 4..7:
      prot_msg="weak";
      break;
    case 8..11:
      prot_msg="nice";
      break;
    case 12..15:
      prot_msg="well";
      break;
    case 16..19:
      prot_msg="good";
      break;
    case 20..23:
      prot_msg="very well";
      break;
    case 24..27:
      prot_msg="extremly well";
      break;
    default:
      prot_msg="battle tank";
      break;
  }
  if(imm)
    prot_msg+=(" ("+ac+")");

  if(objectp(att_ob=tp->query_attack()))
    victim=att_ob->NAME;
  else
    victim="no-one";

  switch(tp->query_size()) {
    case 0:
      size="any";
      break;
    case 1:
      size="tiny";
      break;
    case 2:
      size="small";
      break;
    case 3:
      size="medium";
      break;
    case 4:
      size="large";
      break;
    default:
      size="x-large";
      break;
  }

  stat="";
  if(tp->query_poisoned())
    stat+="poisoned, ";
  if(tp->query_intoxination())
    stat+="drunken, ";
  if(tp->query_soaked())
    stat+="soaked, ";
  if(tp->query_stuffed())
    stat+="stuffed, ";
  if(stat!="")
    stat=stat[0..<3];

  if(!(religion=tp->query_religion()))
    religion="Atheist";

  got=tp->query_exp_perc_lev();
  if(got>=100)
    got=0;
  else
    got=100-got;

  if(!(sw=tp->query_screen_width()))
    sw=78;
  else
    sw-=2;

  tmp=sprintf("\
  guild: %s\n  religion: %s\n\
  level: %d/%d/%d%s\n  size: %s\n\
  exp.to.level: %d%%\n  alignment: %s\n\
  race: %s\n  current weight: %d\n\
  money: %d\n  experience: %d\n\
  combat: %d%%",
capitalize(GM->query_name(tp->query_real_guild())),religion,
tp->query_level(),lg,tp->calculate_level_for_exp(xp),
(imm?"/"+tp->query_wiz_level():""),size,
got,tp->query_al_title(),
tp->query_race(),tp->query_weight(),
tp->query_money(),xp,
tp->query_exp_perc_lev());

  printf("%'~'*s\n%|*s\n%'~'*s\n%-.2#*s\n%'~'*s\n\
%-*s%-*s\n\
%-*s%-*s\n\
%-*s%-*s\n\
%-*s%-*s\n\
%-*s%-*s\n\
%-*s%-*s\n\
%-*s%-*s\n\
%s\
%'~'*s\n\
%|.6#*s\n\
%'~'*s\n",
sw,"~",sw,(cn+" IN HOLY MISSION"+(got?"":"*")),sw,"~",sw,tmp,sw,"~",
sw/2,"  health:",
sw/2,"  "+tp->query_hp()+"["+max_hp+"]",
sw/2,"  power:",
sw/2,"  "+tp->query_sp()+"["+tp->query_max_sp()+"]",
sw/2,"  vitals:",sw/2,"  "+stat,
sw/2,"  protection:",sw/2,"  "+prot_msg,
sw/2,"  mood:",sw/2,"  "+tp->query_mode(),
sw/2,"  wimpy:",sw/2,"  "+(tp->query_wimpy()>=0?
                             tp->query_wimpy()+"% ("
                               +(max_hp*tp->query_wimpy()/100)
                               +" hp) (dir: "+tp->query_wimpydir()+")":
                             "off"),
sw/2,"  attacked by:",sw/2,"  "+victim,
(imm?
   sprintf("%-*s%-*s\n",sw/2,"  environment:",sw/2,"  "+loc):
   ""),
sw,"~",
sw,"DEX: "+tp->query_dex()+
"\nWIS: "+tp->query_wis()+
"\nCON: "+tp->query_con()+
"\nINT: "+tp->query_int()+
"\nSTR: "+tp->query_str()+
"\nCHR: "+tp->query_chr(),
sw,"~");
  return 1;
}

string help() {
  object tp;

  tp=this_player();
  if(!tp)
    return "";
  else
    return "\
Command:\tscore\n\
Arguments:\tnone.\n\
See also:\t"+
(tp->query_immortal() || tp->query_testchar()?
   "stat":
   "")+"\n\
\n\
This command displays information about yourself.\n";
}
