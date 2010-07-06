<?php
// $Id$

/**
 * @file
 *   drush integration for batchbook.
 */

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * @see drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function batchbook_api_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  //$items['solr-phpclient'] = array(
  $items['batchbook-client'] = array(
    //'callback' => 'apachesolr_drush_solr_phpclient',
    'callback' => 'batchbook_api_drush_batchbook_api',
    'description' => dt('Downloads the required Batchbook PHP API from github.com/batchblue.'),
    'arguments' => array(
      'path' => dt('Optional. A path to the batchbook module. If omitted Drush will use the default location.'),
    ),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function batchbook_api_drush_help($section) {
  switch ($section) {
    case 'drush:batchbook-client':
      return dt("Downloads the required Batchbook PHP API from github.com/batchblue. Include an optional path to the batchbook module installation, or if the module is not yet enabled.");
  }
}

/**
 * Example drush command callback.
 *
 * This is where the action takes place.
 *
 * In this function, all of Drupals API is (usually) available, including
 * any functions you have added in your own modules/themes.
 *
 * To print something to the terminal window, use drush_print().
 *
 */
function batchbook_api_drush_batchbook_api() {
  $args = func_get_args();
  if (isset($args[0])) {
    $path = $args[0];
  }
  else {
    $path = drupal_get_path('module', 'batchbook_api');
  }
  drush_op('chdir', $path);
  if (drush_shell_exec('git clone git://github.com/batchblue/batchbook-php.git batchbook-client')) {
    drush_log(dt('Batchbook API has been downloaded to @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the Batchbook API to @path', array('@path' => $path)), 'error');
  }
}
