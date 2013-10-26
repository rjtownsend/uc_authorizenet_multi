UC Authorizenet Multi is an Ubercart module that allows users to add multiple payment
gateways (only authorize.net accounts) to their site and select which gateway should 
be associated with a product node. During checkout, the appropriate gateways are charged.

This was originally developed for a political advocacy organization (C4) that collects
donations for candidates and for the C4 itself. For legal purposes, donations for 
candidates must be deposited into a separate bank account than the C4. This module 
allows them to create "products" (ie. donations) that, during checkout, are deposited
into either the C4 bank account or the candidate bank account. The module supports
an unlimited number of authorize.net accounts.

Note: The module currently does not work with line items, such as taxes, and will mostly 
likely fail and eat baby kittens if you have an Ubercart module installed that uses them.

How to configure:

1. Navigate to admin/store/settings/payment/edit/gateways and open the Authorize.net 
   Multi settings fieldset
2. Enter the number of profiles (ie. Authorize.net accounts) you would like to use and 
   click Save configuration
3. Click the unnamed profile; configure API Login ID, Transaction Key, Transaction Mode, 
   and other settings. Click Submit.
4. Do this for all added profiles
5. Create a product node. Under Product information, there is a Payment Gateway Profile 
   dropdown; select the appropriate gateway.
