.pragma library

function getTileColor (owner, isWinningField){
    if (owner === 1){
        return isWinningField ? '#366399' : '#A6B7CC';
    }
    else if (owner === 2){
        return isWinningField ? '#CC4A3D' : '#FF9D80';
    }
    else{
        return 'gray'
    }
}

function getImage (owner){
    if (owner === 1){
        return 'qrc:/img/gfx/cross.png';
    }
    else if (owner === 2){
        return 'qrc:/img/gfx/nought.png';
    }
    else {
        return '';
    }
}

function isPlayerActive(engine, playerId){
    return engine.active
            && (engine.currentPlayer === playerId);
}
