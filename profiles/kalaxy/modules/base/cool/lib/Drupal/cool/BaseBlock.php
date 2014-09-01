<?php

namespace Drupal\cool;

abstract class BaseBlock implements Controllers\BlockController {

  static public function getId() {
    throw new \Exception('You need to implement the getId() method');
  }

  static public function getAdminTitle() {
    throw new \Exception('You need to implement the getAdminTitle() method');
  }

  static public function getDefinition() {
    return array();
  }

  static public function getConfiguration() {
    return array();
  }

  static public function saveConfiguration($edit) {
    
  }

  static public function getSubject() {
    return '';
  }

  static public function getContent() {
    throw new \Exception('You need to implement the getContent() method');
  }

}
