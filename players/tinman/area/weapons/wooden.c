inherit"obj/weapon";

reset(arg){
::reset(arg);
if (arg) return;
set_name("wooden sword");
set_alt_name("sword");
set_short("A wooden Taoist sword");
set_long("A thin wooden sword made and polished to perfection. It's mainly"+
" used for Taoist ceremonies. Where did that boy get this?\n");
set_class(5);
set_weight(1);
set_value(100);

}
int query_object_type()
{
return 4;
}
int query_three_quest(){
return 1;
}
