<?php

class RealtyController extends EntityAPIController{
	//Поля по умолчанию создаём
	public  function create(array $values = array()){
		global $user;
		$values += array(
			'created' => REQUEST_TIME,
			'uid' => $user->uid,
		);
		return parent::create($values);
	}
	//формируем на вывод
	public function buildContent($entity,$view_mode = 'full', $langcode = NULL, $content = array()){
		$wrapper = entity_metadata_wrapper('realty',$entity);
		$content['author'] = array('#markup' => 
			t('Добавил -  !uid<br>',
                                    array(  => $entity->uid)));

		$content['created'] = array(
			'#markup' => 
				t('Дата создания -  !crtd<br>',
					array('!crtd'=>	
						date('d.m.Y h:i',$entity->created)
					)
				)
			);
                
		$content['original'] = array(
			'#markup' => 
				t('Оригинальная ссылка -  !link<br>',
					array('!link'=>	
						$entity->original
					)
				)
			);
                
		return parent::buildContent($entity,$view_mode,$langcode,$content);
	}
}