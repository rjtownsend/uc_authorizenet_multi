<?php

// Displays a form for admins to enter credit card profile information
function uc_authorizenet_multi_profile_edit_form($form_state, $profile_id) {
  $form = array();
  $profile_id = (int)$profile_id;	
  $form['profile_id'] = array(
    '#type' => 'value',
    '#value' => $profile_id,
  );
  $form['uc_authnet_multi_profile_name_'.$profile_id] = array(
    '#type' => 'textfield',
    '#title' => t('Profile Name'),
    '#default_value' => variable_get('uc_authnet_multi_profile_name_'.$profile_id, ''),
  );
  $form['api_id_key'] = array(
    '#type' => 'fieldset',
    '#title' => t('API Login ID and Transaction Key'),
    '#description' => t('This information is required for Ubercart to interact with your payment gateway account.  It is different from your login ID and password and may be found through your account settings page.'),
  );
  $form['api_id_key']['uc_authnet_multi_api_login_id_'.$profile_id] = array(
    '#type' => 'textfield',
    '#title' => t('API Login ID'),
    '#default_value' => variable_get('uc_authnet_multi_api_login_id_'.$profile_id, ''),
  );
  $form['api_id_key']['uc_authnet_multi_api_transaction_key_'.$profile_id] = array(
    '#type' => 'textfield',
    '#title' => t('Transaction Key'),
    '#default_value' => variable_get('uc_authnet_multi_api_transaction_key_'.$profile_id, ''),
  );
  $form['aim_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('AIM settings'),
    '#description' => t('These settings pertain to the Authorize.Net AIM payment method for card not present transactions.'),
  );
  $form['aim_settings']['uc_authnet_multi_aim_txn_mode_'.$profile_id] = array(
    '#type' => 'radios',
    '#title' => t('Transaction mode'),
    '#description' => t('Only specify a developer test account if you login to your account through https://test.authorize.net.<br/>Adjust to live transactions when you are ready to start processing real payments.'),
    '#options' => array(
      'live' => t('Live transactions in a live account'),
      'live_test' => t('Test transactions in a live account'),
      'developer_test' => t('Developer test account transactions'),
    ),
    '#default_value' => variable_get('uc_authnet_multi_aim_txn_mode_'.$profile_id, 'live_test'),
  );
  $form['aim_settings']['uc_authnet_multi_aim_email_customer_'.$profile_id] = array(
    '#type' => 'checkbox',
    '#title' => t('Tell Authorize.net to e-mail the customer a receipt based on your account settings.'),
    '#default_value' => variable_get('uc_authnet_multi_aim_email_customer_'.$profile_id, FALSE),
  );
  $form['aim_settings']['uc_authnet_multi_response_debug_'.$profile_id] = array(
    '#type' => 'checkbox',
    '#title' => t('Log full API response messages from Authorize.net for debugging.'),
    '#default_value' => variable_get('uc_authnet_multi_response_debug_'.$profile_id, FALSE),
  );  
  $form['submit_button'] = array(
   '#type' => 'submit',
   '#value' => 'Submit',
  );  
  return $form;	
}

function uc_authorizenet_multi_profile_edit_form_submit($form, &$form_state) {  
  $profile_id = $form['profile_id']['#value'];  
  variable_set('uc_authnet_multi_profile_name_'.$profile_id, $form['uc_authnet_multi_profile_name_'.$profile_id]['#value']);  
  variable_set('uc_authnet_multi_api_login_id_'.$profile_id, $form['api_id_key']['uc_authnet_multi_api_login_id_'.$profile_id]['#value']);  
  variable_set('uc_authnet_multi_api_transaction_key_'.$profile_id, $form['api_id_key']['uc_authnet_multi_api_transaction_key_'.$profile_id]['#value']);  
  variable_set('uc_authnet_multi_aim_txn_mode_'.$profile_id, $form['aim_settings']['uc_authnet_multi_aim_txn_mode_'.$profile_id]['#value']);  
  variable_set('uc_authnet_multi_aim_email_customer_'.$profile_id, $form['aim_settings']['uc_authnet_multi_aim_email_customer_'.$profile_id]['#value']);  
  variable_set('uc_authnet_multi_response_debug_'.$profile_id, $form['aim_settings']['uc_authnet_multi_response_debug_'.$profile_id]['#value']);  
    
  $form_state['redirect'] = 'admin/store/settings/payment/edit/gateways';
  
  drupal_set_message(t('The payment details for that profile have been saved.'));  
}
