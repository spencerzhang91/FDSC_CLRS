def Towers(size, fromStack, toStack, spareStack):
    '''
    The parameters of this function have a fixed order which means that:
    [size]-> the total disks of the tower
    [fromStack]-> current move origin
    [toStack]-> current move destination
    [spareStack]-> the stick is spared in current move
    "current move" means one attemp to move a disk from a stick to another and
    the parameters "fromStack" and so on are not the name of certain stick but
    just the stack you do relevant operation. Any stack can be a "fromStack"
    as long as you try to remove a disk from it in "current move".
    '''
    if size == 1:
        print('Move disk from ', fromStack, 'to ', toStack)
    else:
        Towers(size-1, fromStack, spareStack, toStack)
        Towers(1, fromStack, toStack, spareStack)
        Towers(size-1, spareStack, toStack, fromStack)

Towers(4, 'f', 't', 's')
