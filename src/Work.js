import React, {Component} from 'react';

export default class extends Component {
  constructor() {
    super();
  }
  render() {
    return (
      <div>
        {this.props.children}
      </div>
    )
  }
}
