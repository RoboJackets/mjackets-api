.. _digital_out:

DigitalOut
##########

.. doxygenclass:: DigitalOut
   :project: mjackets-api
   :members:

Example Usage:
**************

.. code-block:: cpp

    DigitalOut myLed(PIN_E5, PullNone, PushPull);
    
    while(1)
    {
        myLed.Toggle()
        Delay(100);
    }

.. note::
    Make sure that you have initialized the GPIO peripheral clock for
    your GPIO port before initializing the pin as an output. 