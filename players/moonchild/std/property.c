static mapping property=([ ]);

void set(string prop, mixed val) {
  mixed *tmp;
  tmp=({ m_indices(property), m_values(property) });
  if(!property[prop])
    property=mkmapping(tmp[0] + ({ prop }), tmp[1] + ({ val }));
  else {
    int n;
    n=member_array(prop, tmp[0]);
    tmp[1][n]=val;
    property=mkmapping(tmp[0], tmp[1]);
  }
}

int unset(string prop) {
  if(!property[prop]) return 0;
  m_delete(property, member_array(prop, m_indices(property)));
  return 1;
}
    
mixed query(string prop) {
  return property[prop];
}
