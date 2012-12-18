<?php
function realty_view($realty) {
  drupal_set_title(entity_label('realty', $realty));
  return entity_view('realty', array(entity_id('realty', $realty) => $realty), 'full');
}



