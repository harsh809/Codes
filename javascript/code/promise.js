const cart = ["shoes","watch","t-shirts"];

// createorder(cart,function (orderId){
//     proceedToPayment(orderId, function (paymentInfo){
//         showOrdersummary(paymentInfo , function (paymentInfo){
//             updatewalletBalance();
//         });
//     });
// });

createorder(cart)
    .then(function(orderId){
        return proceedtopayment(orderId);
    })
    .then(function (paymentinfo){
        return showordersummary(paymentinfo);
    });


createorder(cart)
    .then((orderId) => proceedtopayment(orderId))
    .then((paymentinfo) => showordersummary(paymentinfo))
    .then((paymentinfo) => PaymentRequestUpdateEvent(paymentinfo));