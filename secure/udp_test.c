receive_imp(string ip,string buf)
{
object herp;
string *s;
string remsg;
string ipnr;
string port;

  herp=find_player("herp");
  if (herp) {
    tell_object(herp,"receive_imp: ip = "+ip+" buf = "+buf+"\n");
  }
  if (buf[0..8]=="@@@ping_q") {
     s=explode(buf,"||");
     if (explode(s[1],":")[1]=="PaderMud") {	/* Only Pader allowed */
	remsg="@@@ping_a||NAME:HolyMission||PORTUDP:2500@@@\n";
	if (herp) tell_object(herp,"generated msg: "+remsg);
	send_imp("131.234.42.22",2500,remsg);
     }
  }
}

xxx() {
#if 1
  send_imp("131.234.42.22",2500,"@@@gwizmsg||NAME:HolyMission||PORTUDP:2500||WIZNAME:RemoteHerp||EMOTE:This is an emote (remote)||GWIZ:This is a recording@@@\n");
  send_imp("140.78.3.1",2500,"@@@gtell||NAME:HolyMission||PORTUDP:2500||WIZFROM:Herp||WIZTO:herp||MSG:This is a recording@@@\n");
  send_imp("131.234.42.22",2500,"@@@gtell||NAME:HolyMission||PORTUDP:2500||WIZFROM:Herp||WIZTO:herp||MSG:This is a recording@@@\n");
  send_imp("131.234.42.22",2500,"@@@gtell||NAME:HolyMission||PORTUDP:2500||WIZFROM:Herp||WIZTO:llort||MSG:This is a recording@@@\n");
#endif
}
