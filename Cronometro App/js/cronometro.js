(function($) {
  AddTableRow = function() {
    var nomeRobo = $("#nomeRobo").val();
    var Horas= document.getElementById("Horas").innerHTML
    var Minutos= document.getElementById("Minutos").innerHTML
    var Segundos= document.getElementById("Segundos").innerHTML
    var Centesimas = document.getElementById("Centesimas").innerHTML


    console.log(nomeRobo);
    var newRow = $("<tr>");
    var cols = "";

    cols += '<td>'+nomeRobo+'</td>';
    cols += '<td>'+Horas+''+Minutos+''+Segundos+''+Centesimas+'</td>';

    newRow.append(cols);
    $("#products-table").append(newRow);
    return false;
  };
})(jQuery);
