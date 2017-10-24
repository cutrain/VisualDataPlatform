import React, { Component } from 'react';
import ReactDOM from 'react-dom';
import { BrowserRouter, Router, Route } from 'react-router-dom';
import Homepage from './Homepage'

export default class extends Component {
  constructor() {
    super();
  }

  render() {
    return <BrowserRouter basename="/">
      <Route path='/' component={Homepage} />
    </BrowserRouter>
  }
}
