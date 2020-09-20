.. _external_interrupt:

ExternalInterrupt
#################

.. doxygenclass:: ExternalInterrupt
   :project: mjackets-api
   :members:

Example Usage:
**************

.. code-block:: cpp

    void myCallback(void){}

    ExternalInterrupt myPin(PIN_E5, &myCallback, PullNone, INTERRUPT_RISING, 0);
    
    

.. note::
    Make sure that you have initialized the GPIO peripheral clock for
    your GPIO port before initializing the pin as an external interrupt. 