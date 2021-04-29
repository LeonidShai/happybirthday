#include "Mediator.h"

BaseComponent::BaseComponent(Mediator *mediator):
    _mediator(mediator)
{

}

void BaseComponent::setMediator(Mediator *mediator)
{
    _mediator = mediator;
}

