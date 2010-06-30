<?php
// $Id:$

/**
 * @file
 * Contains the admin page callbacks for the Batchbook module.
 */

/**
 * The settings form at admin/settings/batchbook.
 */
function batchbook_api_settings_form() {
  $form = array();

  // Use the username field to collapse the API settings fieldset.
  $username = variable_get('batchbook_api_username', '');

  $form['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('Batchbook API settings'),
    '#description' => t('Use your Batchbook login information for these username and token fields.'),
    '#collapsible' => !empty($username),
    '#collapsed' => !empty($username),
    '#weight' => -10,
  );
  $form['api']['batchbook_api_account_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Account name'),
    '#description' => t('Your personalized Batchbook URL.'),
    '#default_value' => variable_get('batchbook_api_account_name', ''),
    '#required' => TRUE,
  );
  $form['api']['batchbook_api_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Security token'),
    '#description' => t('Find your security token by...'),
    '#required' => TRUE,
    '#default_value' => variable_get('batchbook_api_token', ''),
  );
  
  // Validate handler
  //$form['#validate'][] = 'batchbook_api_settings_form_validate';
  //$form['#submit'][] = 'batchbook_api_settings_form_submit';
  
  return system_settings_form($form);
}

/*
function batchbook_api_demo() {
  // Attempt to create a Person Service object
  $bb_person_service = batchbook_api_person_service();
  // Display an error message if the person service creation failed.
  if (!$bb_person_service) {
    return t('Could not create a person service object.');
  }

  $output = '';
  return $output;
}
*/
